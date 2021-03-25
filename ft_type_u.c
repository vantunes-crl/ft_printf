/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantunes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:37:15 by vantunes          #+#    #+#             */
/*   Updated: 2021/03/22 15:37:18 by vantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_isminus(t_flags *flags, char *str)
{
	int char_count;

	char_count = 0;
	if (flags->dot >= 0)
		char_count += ft_print_width(flags->dot - 1, ft_strlen(str) - 1, 1);
	char_count += ft_print_prec(ft_strlen(str), str);
	char_count += ft_print_width(flags->width, flags->dot, 0);
	return (char_count);
}

static	int	ft_printuint(t_flags *flags, char *str)
{
	int char_count;

	char_count = 0;
	if (flags->dot >= 0 || flags->minus == 1)
		flags->zero = 0;
	if (flags->dot <= ft_strlen(str))
		flags->dot = ft_strlen(str);
	if (flags->minus == 1)
		char_count += ft_isminus(flags, str);
	if (flags->minus == 0 && flags->zero == 0)
	{
		char_count += ft_print_width(flags->width, flags->dot, 0);
		char_count += ft_print_width(flags->dot, ft_strlen(str), 1);
		char_count += ft_print_prec(ft_strlen(str), str);
	}
	if (flags->minus == 0 && flags->zero == 1)
	{
		char_count += ft_print_width(flags->width, ft_strlen(str), 1);
		char_count += ft_print_prec(ft_strlen(str), str);
	}
	return (char_count);
}

int			ft_isuint(t_flags *flags, unsigned int uint)
{
	int		char_count;
	char	*str;

	char_count = 0;
	if (flags->dot == 0 && uint == 0)
		return (char_count += ft_print_width(flags->width, 0, 0));
	if (uint == 0 && flags->dot > 0 && flags->minus == 1)
	{
		char_count += ft_print_width(flags->dot, 0, 1);
		char_count += ft_print_width(flags->width, flags->dot, 0);
		return (char_count);
	}
	if (uint == 0 && flags->dot > 0 && flags->minus == 0)
	{
		char_count += ft_print_width(flags->width, flags->dot, 0);
		char_count += ft_print_width(flags->dot, 0, 1);
		return (char_count);
	}
	else
	{
		str = ft_itoa_ull(uint, 10);
		char_count += ft_printuint(flags, str);
	}
	free(str);
	return (char_count);
}
