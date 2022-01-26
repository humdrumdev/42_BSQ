#include "./includes/ultimate_header.h"

int main(int ac, char **av)
{
	int i;
	int lines;
	char set[5];
	int line_len;

	i = 0;
	while (++i < ac)
	{
		ft_bsq(av[i], &lines, &line_len, set);
		if (i < (ac - 1))
			write(STDOUT_FILENO, "\n", 1);
	}
	if (ac == 1)
	{
		if (!ft_create_file())
			exit(EXIT_FAILURE);
		ft_bsq("bsq_map", &lines, &line_len, set);
	}
	exit(EXIT_SUCCESS);
}

void ft_bsq(char *fname, int *lines, int *line_len, char *set)
{
	int **map;
	char **buff;
	struct s_square square;
	struct s_square my_square;
	int j;

	if (ft_check_valid_file(fname, lines, line_len, set) <= 0)
		write(2, "map error\n", 10);
	else
	{
		square.y = *lines;
		square.x = *line_len;
		map = (int **)malloc(square.y * sizeof(int *));
		j = 0;
		while (j < square.y)
			map[j++] = malloc((square.x) * sizeof(int));
		buff = 0;
		buff = ft_read_map(buff, fname, square);
		ft_get_binary_map(buff, map, square, set[1]);
		ft_check_square(map, square.y, square.x);
		my_square = ft_get_lagest_number(map, square);
		ft_print_square(buff, set, square, my_square);
		free(buff), free(map);
	}
}

int ft_create_file(void)
{
	char *buff;
	int fdes;
	int num_chars;

	buff = malloc(1 << 20);
	if (!buff)
		return (0);
	num_chars = read(0, buff, 1 << 20);
	if (num_chars <= 0)
	{
		free(buff);
		return (0);
	}
	fdes = open("bsq_map", O_WRONLY | O_CREAT, S_IRWXU);
	if (fdes < 0)
		return (0);
	write(fdes, buff, num_chars);
	close(fdes);
	free(buff);
	return (1);
}
