NAME = libftprintf.a

SRCS =	ft_flag_parse.c \
	ft_printf.c ft_flags.c ft_parse_types.c \
	ft_is_type_percent.c ft_is_type_di.c ft_is_type_x.c \
	ft_type_c.c ft_type_p.c ft_type_s.c \
	ft_type_u.c ft_itoa_ull.c \
	ft_itoa.c ft_printf_utils.c  ft_printf_utils2.c\

OBJS = $(SRCS:.c=.o)

CC = gcc

FLAGS = -c -I -Wall -Wetra -Werror

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

all: $(NAME)

bonus: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re