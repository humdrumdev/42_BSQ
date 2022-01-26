#include "../includes/ultimate_header.h"

void ft_check_square(int **map, int y, int x)
{
	int i;
	int j;

	i = 1;
	while (i < y)
	{
		j = 0;
		while (j < x - 1)
		{
			if (i != 0 && j != 0)
				map[i][j] = ft_get_smallest(map, i, j) + map[i][j];
			j++;
		}
		i++;
	}
}

int ft_get_smallest(int **map, int i, int j)
{
	if (!map[i][j])
		return (0);
	if (map[i][j - 1] < map[i - 1][j] && map[i][j - 1] < map[i - 1][j - 1])
		return (map[i][j - 1]);
	else if (map[i - 1][j] < map[i - 1][j - 1])
		return (map[i - 1][j]);
	else
		return (map[i - 1][j - 1]);
}

void ft_print_square(char **buff, char *charset,
					 struct s_square original_map, struct s_square square)
{
	int i;
	int k;

	i = 0;
	while (i < original_map.y)
	{
		k = 0;
		while (k < original_map.x)
		{
			if (((i <= square.x) && (k <= square.y)) && ((i > (square.x - square.nb)) && (k > (square.y - square.nb))))
				write(STDOUT_FILENO, &charset[2], 1);
			else
				write(STDOUT_FILENO, &buff[i][k], 1);
			k++;
		}
		i++;
	}
}
