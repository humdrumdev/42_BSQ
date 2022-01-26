#include "../includes/ultimate_header.h"

int ft_valid_line(char *fname, char *set, int sec_line_len, int fst_line_len)
{
	char *buff;
	char *sec_line;
	int fdes;
	int status;

	buff = malloc((fst_line_len + 1) * sizeof(char));
	sec_line = malloc((sec_line_len + 1) * sizeof(char));
	if (!buff || !sec_line)
		return (-1);
	fdes = open(fname, O_RDONLY);
	if (fdes < 0)
		return (fdes);
	if (read(fdes, buff, fst_line_len) < 0)
		return (-1);
	free(buff);
	status = read(fdes, sec_line, sec_line_len);
	if (status < 0)
		return (status);
	sec_line[sec_line_len] = '\0';
	status = ft_check_line(sec_line, sec_line_len, set);
	free(sec_line);
	if (close(fdes) < 0)
		return (-1);
	return (status);
}

int ft_check_line(char *str, int stlen, char *set)
{
	int i;

	i = 0;
	while (str[i] && (i < (stlen - 1)))
	{
		if (str[i] != set[0] && str[i] != set[1])
			return (-2);
		i++;
	}
	if (str[i] != '\n' || (i < stlen - 1))
		return (-1);
	return (1);
}

int ft_check_valid_chars(char *charset)
{
	if (charset[3] != '\n')
		return (-1);
	if ((charset[0] == charset[1]) || (charset[0] == charset[2]) || (charset[1] == charset[2]))
		return (-1);
	return (1);
}

int ft_secd_line_len(char *fname, int first_len)
{
	int len;
	int status;
	int fdes;
	char buff[17];

	fdes = open(fname, O_RDONLY);
	if (fdes < 0)
		return (fdes);
	status = read(fdes, buff, first_len);
	if (status < first_len)
		return (-1);
	len = 0;
	buff[0] = '\0';
	while (buff[0] != '\n')
	{
		status = read(fdes, buff, 1);
		if (status < 0)
			return (status);
		len++;
	}
	if (close(fdes) < 0)
		return (-1);
	return (len);
}
