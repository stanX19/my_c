NAME	= rush02
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= main.c rush02.c ft_putchar.c

run: all
	./$(NAME)
all:
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
clean:
	rm -rf $(NAME)
fclean: clean

re: fclean all
