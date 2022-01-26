#ifndef ALGO_H
# define ALGO_H

struct s_square
{
	int	x;
	int	y;
	int	nb;
};

void			ft_check_square(int **map, int y, int x);
int				ft_get_smallest(int **map, int i, int j);
void			ft_get_binary_map(char **buff, int **map,
					struct s_square original_map, char obstacle);
void			ft_print_square(char **buff, char *charset,
					struct s_square original_map, struct s_square square);
char			**ft_read_map(char **buff, char *fname, struct s_square square);
struct s_square	ft_get_lagest_number(int **map, struct s_square square);

#endif
