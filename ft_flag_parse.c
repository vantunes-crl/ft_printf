/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantunes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:33:45 by vantunes          #+#    #+#             */
/*   Updated: 2021/03/22 15:33:50 by vantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flag_parse(t_flags *flags, va_list args, const char *str, int pos)
{
	while (str[pos])
	{
		if (str[pos] == '0' && flags->minus == 0 && flags->width == 0)
			flags->zero = 1;
		if (str[pos] == '+')
			flags->plus = 1;
		if (str[pos] == '.')
			pos = ft_isdot(flags, args, str, pos);
		if (str[pos] == '-')
			flags->minus = 1;
		if (str[pos] == '*')
			flags = ft_isstar(flags, args);
		if (ft_isdigit(str[pos]))
			flags = ft_digitflag(flags, str[pos]);
		if (ft_strchr(ALLCARACTERES, str[pos]))
		{
			flags->type = str[pos];
			break ;
		}
		pos++;
	}
	return (pos);
}
