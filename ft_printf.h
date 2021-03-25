/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantunes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:36:07 by vantunes          #+#    #+#             */
/*   Updated: 2021/03/22 15:36:08 by vantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct	s_flags
{
	int dot;
	int minus;
	int zero;
	int star;
	int width;
	int type;
	int plus;

}				t_flags;

t_flags			*ft_digitflag(t_flags *flags, char c);
int				ft_flag_parse(t_flags *flags, va_list args,
								const char *str, int pos);
int				ft_isdot(t_flags *flags, va_list args,
									const char *str, int pos);
t_flags			ft_init_flags(void);
t_flags			*ft_isstar(t_flags *flags, va_list args);

int				ft_strlen(const char *str);
int				ft_isdigit(char c);
int				ft_strchr(char *str, char c);
int				ft_putchar(char c);
char			*ft_itoa_u(unsigned int i, int base);
char			*ft_itoa(long int i, int base);
char			*ft_itoa_ull(unsigned long long ull, int base);
char			*ft_tolower_str(char *str);
char			*ft_strdup(char *str);

int				ft_parse_types(t_flags *flags,
							const char *str, int pos, va_list args);
int				ft_print_width(int width, int minus, int zero);
int				ft_print_prec(int prec, char *str);
int				ft_ischar(t_flags *flags, va_list args);
int				ft_isstring(t_flags *flags, char *str);
int				ft_isint(t_flags *flags, long int d_i);
int				ft_ispointer(t_flags *flags, unsigned long long ull);
int				ft_ishex(t_flags *flags, unsigned int hex, int lower);
int				ft_ispercent(t_flags *flags);
int				ft_isuint(t_flags *flags, unsigned int uint);

int				ft_printf(const char *str, ...);

# define ALLCARACTERES "cspdiuxX%"
# define ALLFLAGS "0.-*"
#endif
