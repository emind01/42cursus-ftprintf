NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_w.c ft_printf_n.c

OBJS = $(SRCS:.c=.o)

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(name)

re:
	fclean all

.PHONY: all clean fclean re

