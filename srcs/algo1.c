#include "../includes/ultimate_header.h"

struct s_square ft_get_lagest_number(int **map, struct s_square square)
{
	int i;
	int j;
	struct s_square my_square;

	i = 0;
	j = 0;
	my_square.nb = 0;
	while (i < square.y)
	{
		j = 0;
		while (j < square.x - 1)
		{
			if (map[i][j] > my_square.nb)
			{
				my_square.nb = map[i][j];
				my_square.x = i;
				my_square.y = j;
			}
			j++;
		}
		i++;
	}
	return (my_square);
}

char **ft_read_map(char **buff, char *fname, struct s_square square)
{
	char set[2];
	int fd;
	int j;

	fd = open(fname, O_RDONLY);
	if (fd < 0)
		return (NULL);
	buff = (char **)malloc((square.y) * sizeof(char *));
	if (!buff)
		return (NULL);
	set[0] = '\0';
	while (set[0] != '\n')
	{
		if (read(fd, set, 1) < 0)
			return (NULL);
	}
	j = 0;
	while (j < square.y)
		buff[j++] = malloc(square.x * sizeof(char));
	j = 0;
	while (j < square.y)
		read(fd, buff[j++], square.x);
	close(fd);
	return (buff);
}

void ft_get_binary_map(char **buff, int **map,
					   struct s_square original_map, char obstacle)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < original_map.y)
	{
		j = 0;
		while (j < original_map.x - 1)
		{
			if (buff[i][j] == obstacle)
				map[i][j] = 0;
			else
				map[i][j] = 1;
			j++;
		}
		i++;
	}
}
