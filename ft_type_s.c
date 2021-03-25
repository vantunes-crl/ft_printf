/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantunes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:37:05 by vantunes          #+#    #+#             */
/*   Updated: 2021/03/24 16:46:45 by vantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_isminuss(t_flags *flags, char *str)
{
	int char_count;
	int prec;

	char_count = 0;
	prec = ft_print_prec(flags->dot, str);
	char_count = ft_print_width(flags->width, prec, 0);
	char_count += prec;
	return (char_count);
}

int				ft_isstring(t_flags *flags, char *str)
{
	int char_count;
	int prec;

	char_count = 0;
	if (!str)
		str = "(null)";
	if (flags->dot <= -1)
		flags->dot = ft_strlen(str);
	if (flags->minus == 0 && flags->zero == 1 && flags->width > ft_strlen(str))
	{
		char_count += ft_print_width(flags->width, ft_strlen(str), 1);
		char_count += ft_print_prec(flags->dot, str);
		return (char_count);
	}
	if (flags->minus == 1)
		char_count += ft_isminuss(flags, str);
	if (flags->dot >= ft_strlen(str))
		flags->dot = ft_strlen(str);
	if (flags->minus == 0)
	{
		char_count = ft_print_width(flags->width, flags->dot, 0);
		char_count += ft_print_prec(flags->dot, str);
	}
	return (char_count);
}
