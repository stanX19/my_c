SRCDIR			= .
SRCS			= $(addprefix $(SRCDIR)/,\
	ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstsize.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_strndup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
)
OBJDIR			= objs
OBJS			= $(subst $(SRCDIR)/,$(OBJDIR)/,$(subst .c,.o,$(SRCS)))
OBJDIRS			= $(sort $(dir $(OBJS)))

HEADERS			= libft.h

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror #-fsanitize=address -g3
IFLAGS			= -I.
RM				= rm -rf

NAME			= libft.a

UP				= \033[1A
FLUSH			= \033[2K

TESTER			= libftTester


all: $(NAME)

bonus: $(NAME)

$(TESTER):
	git clone https://github.com/Tripouille/libftTester.git $(TESTER)

test: $(TESTER)
	make -C $(TESTER) a

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

$(OBJDIRS):
	mkdir -p $@
	@echo "$(UP)$(FLUSH)$(UP)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS) | $(OBJDIRS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@echo "$(UP)$(FLUSH)$(UP)"

clean:
	@$(RM) $(OBJDIR)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(TESTER)

re: fclean $(NAME)

.PHONY: all clean fclean re
