CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

NAME		= libftprintf.a
INCLUDE		= ft_printf.h

SRCS =	ft_flag_parse.c \
	ft_printf.c ft_flags.c ft_parse_types.c \
	ft_is_type_percent.c ft_is_type_di.c ft_is_type_x.c \
	ft_type_c.c ft_type_p.c ft_type_s.c \
	ft_type_u.c ft_itoa_ull.c \
	ft_itoa.c ft_printf_utils.c  ft_printf_utils2.c\

OBJS		= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(INCLUDE)
			ar -rcs $(NAME) $(OBJS)
			ranlib	$(NAME)

bonus:		$(NAME)

.c.o:
			$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $(<:.c=.o)

clean:
			$(RM) $(OBJS) $(BONUS_O)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

rebonus:	fclean bonus

.PHONY:		all clean fclean re bonus rebonus