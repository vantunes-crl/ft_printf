/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_type_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantunes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 13:24:54 by vantunes          #+#    #+#             */
/*   Updated: 2021/03/28 13:24:56 by vantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_isminus(t_flags *flags, char *str)
{
	int char_count;

	char_count = 0;
	if (flags->dot > ft_strlen(str))
		char_count += ft_print_width(flags->dot, ft_strlen(str), 1);
	char_count += ft_print_prec(ft_strlen(str), str);
	char_count += ft_print_width(flags->width, flags->dot, 0);
	return (char_count);
}

static	int		ft_printhex(t_flags *flags, int lower, char *str)
{
	int char_count;

	char_count = 0;
	if (lower == 1)
		str = ft_tolower_str(str);
	if ((flags->dot >= 0) || (flags->minus == 1))
		flags->zero = 0;
	if (flags->dot <= ft_strlen(str))
		flags->dot = ft_strlen(str);
	if (flags->minus == 1)
		char_count += ft_isminus(flags, str);
	if (flags->minus == 0 && flags->zero == 0)
	{
		char_count += ft_print_width(flags->width, flags->dot, 0);
		if (flags->dot > ft_strlen(str))
			char_count += ft_print_width(flags->dot, ft_strlen(str), 1);
		char_count += ft_print_prec(ft_strlen(str), str);
	}
	if (flags->minus == 0 && flags->zero == 1)
	{
		char_count += ft_print_width(flags->width, ft_strlen(str), 1);
		char_count += ft_print_prec(ft_strlen(str), str);
	}
	free(str);
	return (char_count);
}

int				ft_ishex(t_flags *flags, unsigned int hex, int lower)
{
	char	*str;
	int		char_count;

	char_count = 0;
	if (flags->dot == 0 && hex == 0)
		return (char_count += ft_print_width(flags->width, 0, 0));
	if (hex == 0 && flags->dot > 0 && flags->minus == 1)
	{
		char_count += ft_print_width(flags->dot, 0, 1);
		char_count += ft_print_width(flags->width, flags->dot, 0);
		return (char_count);
	}
	if (hex == 0 && flags->dot > 0 && flags->minus == 0)
	{
		char_count += ft_print_width(flags->width, flags->dot, 0);
		char_count += ft_print_width(flags->dot, 0, 1);
		return (char_count);
	}
	else
	{
		str = ft_itoa_ull(hex, 16);
		char_count = ft_printhex(flags, lower, str);
	}
	return (char_count);
}
