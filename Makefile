CC = gcc
CFLAGS = -Wall -Wextra -Werror
IDIR = includes
LDIR = srcs/*.c
OBJ = *.o
NAME = bsq
FILE = bsq_map
MAIN = main.c


all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(LDIR) -I $(IDIR)
	$(CC) $(CFLAGS) $(MAIN) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)
	rm -f $(FILE)

fclean: clean
	rm -f $(NAME)

re: fclean all
