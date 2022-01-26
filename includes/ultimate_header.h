#ifndef ULTIMATE_HEADER_H
# define ULTIMATE_HEADER_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "algo.h"

int		ft_strlen(char *str);
int		ft_decomp_first_line(char *line, int len, char *charset);
int		ft_valid_line(char *fname, char *set, int sec_line_len, int fst_len);
int		ft_get_first_line(char *fname, char *first_line);
int		ft_check_valid_chars(char *charset);
int		ft_valid_secd_line(char *fname, char *charset, int *line_count);
int		ft_secd_line_len(char *fname, int first_len);
int		ft_check_valid_file(char *fname, int *lines, int *line_len, char *set);
int		ft_check_line(char *str, int stlen, char *set);
char	*ft_check_helper(char *fname, int *lines, int *line_len, char *set);
int		ft_compute_setlen(char *buff, int fdes);
int		ft_create_file(void);
void	ft_bsq(char *fname, int *lines, int *len, char *set);

#endif
