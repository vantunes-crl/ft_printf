/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_types.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantunes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:40:16 by vantunes          #+#    #+#             */
/*   Updated: 2021/03/22 15:40:18 by vantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_types(t_flags *flags, const char *str, int pos, va_list args)
{
	int char_count;

	char_count = 0;
	if (str[pos] == 'c')
		char_count = ft_ischar(flags, args);
	else if (str[pos] == 's')
		char_count = ft_isstring(flags, va_arg(args, char *));
	else if (str[pos] == 'd' || flags->type == 'i')
		char_count = ft_isint(flags, va_arg(args, int));
	else if (str[pos] == 'p')
		char_count = ft_ispointer(flags, va_arg(args, unsigned long long));
	else if (str[pos] == 'u')
		char_count = ft_isuint(flags, va_arg(args, unsigned int));
	else if (str[pos] == 'x')
		char_count = ft_ishex(flags, va_arg(args, unsigned int), 1);
	else if (str[pos] == 'X')
		char_count = ft_ishex(flags, va_arg(args, unsigned int), 0);
	else if (str[pos] == '%')
		char_count = ft_ispercent(flags);
	return (char_count);
}
