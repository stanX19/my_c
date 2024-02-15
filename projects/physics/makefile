SRCDIR	= srcs/
SRCS	=	$(addsuffix .c, \
		main)
LIBS = libbgi.a
CC			= 	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

NAME	=	collision

run: $(NAME)
	./$(NAME)
$(NAME):
	$(CC) $(CFLAGS) $(SRCS) $(LIBS)
clean:
	$(RM) $(NAME)
re: clean run