NAME	= rush01
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= main.c rush01.c ft_putchar.c

run: all
	./$(NAME)
all:
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
clean:
	rm -rf $(NAME)
fclean: clean

re: fclean all
