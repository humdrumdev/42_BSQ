#include "../includes/ultimate_header.h"

int ft_check_valid_file(char *fname, int *lines, int *line_len, char *charset)
{
	int fdes;
	int j;
	char *buff;

	buff = ft_check_helper(fname, lines, line_len, charset);
	if (!buff)
		return (-1);
	fdes = open(fname, O_RDONLY);
	if (fdes < 0)
		return (fdes);
	if (ft_compute_setlen(buff, fdes) < 0)
		return (-1);
	j = 0;
	while (j < *lines)
	{
		if ((read(fdes, buff, *line_len) != *line_len) || (ft_check_line(buff, *line_len, charset) < 0))
			return (-1);
		j++;
	}
	j = ((read(fdes, buff, 1) > 0) || (close(fdes) < 0));
	free(buff);
	return (!j);
}

char *ft_check_helper(char *fname, int *lines, int *line_len, char *charset)
{
	char *buff;

	*line_len = ft_valid_secd_line(fname, charset, lines);
	if (*line_len < 0)
		return (0);
	buff = malloc((*line_len + 1) * sizeof(char));
	buff[*line_len] = '\0';
	return (buff);
}

int ft_compute_setlen(char *buff, int fdes)
{
	int setlen;

	setlen = 0;
	buff[0] = '\0';
	while (buff[0] != '\n')
	{
		if (read(fdes, buff, 1) < 0)
			return (-1);
		setlen++;
	}
	return (setlen);
}
