/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantunes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 13:27:04 by vantunes          #+#    #+#             */
/*   Updated: 2021/03/28 13:27:06 by vantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_printhalf(const char *str, va_list arg)
{
	t_flags flags;
	int		char_count;
	int		i;

	char_count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1])
		{
			flags = ft_init_flags();
			if (ft_strchr(ALLCARACTERES, str[i]) ||
							!ft_isdigit(str[i] || ft_strchr(ALLFLAGS, str[i])))
			{
				i = ft_flag_parse(&flags, arg, str, i + 1);
				if (flags.type == 0)
					break ;
				char_count += ft_parse_types(&flags, str, i, arg);
			}
		}
		else
			char_count += ft_putchar(str[i]);
		i++;
	}
	return (char_count);
}

int			ft_printf(const char *str, ...)
{
	va_list (arg);
	int		char_count;

	va_start(arg, str);
	char_count = ft_printhalf(str, arg);
	va_end(arg);
	return (char_count);
}
