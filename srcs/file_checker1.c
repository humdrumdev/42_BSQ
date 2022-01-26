#include "../includes/ultimate_header.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

int ft_get_first_line(char *fname, char *first_line)
{
	int fdes;
	int status;
	int len;

	fdes = open(fname, O_RDONLY);
	if (fdes < 0)
		return (fdes);
	len = 1;
	status = read(fdes, first_line, 1);
	if (status < 0)
		return (status);
	while ((first_line[len - 1] != '\n') && (len < 16))
	{
		status = read(fdes, first_line + len, 1);
		if (status < 0)
			return (status);
		len++;
	}
	first_line[len] = '\0';
	status = close(fdes);
	return (status);
}

int ft_decomp_first_line(char *line, int len, char *charset)
{
	int i;
	int num_lines;

	charset[4] = '\0';
	charset[3] = line[len - 1];
	charset[2] = line[len - 2];
	charset[1] = line[len - 3];
	charset[0] = line[len - 4];
	num_lines = 0;
	i = 0;
	while ((line[i] <= '9') && (line[i] >= '0') && (i < (len - 4)))
	{
		num_lines = num_lines * 10 + line[i] - '0';
		i++;
	}
	if (i != (len - 4))
		return (-1);
	return (num_lines);
}

int ft_valid_secd_line(char *fname, char *charset, int *line_count)
{
	char first_line[17];
	int status;
	int lines;
	int first_line_len;

	status = ft_get_first_line(fname, first_line);
	if (status < 0)
		return (status);
	first_line_len = ft_strlen(first_line);
	lines = ft_decomp_first_line(first_line, first_line_len, charset);
	if (lines < 0)
		return (lines);
	*line_count = lines;
	status = ft_check_valid_chars(charset);
	if (status < 0)
		return (status);
	status = ft_secd_line_len(fname, first_line_len);
	if (status <= 1)
		return (-1);
	if (ft_valid_line(fname, charset, status, first_line_len) < 0)
		return (-1);
	return (status);
}
