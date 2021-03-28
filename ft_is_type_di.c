/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_type_di.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantunes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 13:23:44 by vantunes          #+#    #+#             */
/*   Updated: 2021/03/28 13:23:46 by vantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_isminuszero1(t_flags *flags, char *str, long int d_i)
{
	int char_count;

	char_count = 0;
	if (d_i < 0)
	{
		char_count += ft_putchar('-');
		flags->width--;
	}
	else if (d_i >= 0 && flags->plus == 1)
	{
		char_count += ft_putchar('+');
		flags->width--;
	}
	char_count += ft_print_width(flags->width, ft_strlen(str), 1);
	char_count += ft_print_prec(ft_strlen(str), str);
	return (char_count);
}

static int		ft_isminuszero(t_flags *flags, char *str, long int d_i)
{
	int char_count;

	char_count = 0;
	if ((d_i < 0 && flags->dot >= 0) || (d_i >= 0 && flags->plus == 1))
		flags->width--;
	char_count += ft_print_width(flags->width, flags->dot, 0);
	if (d_i < 0 && flags->dot >= 0)
		char_count += ft_putchar('-');
	else if (d_i >= 0 && flags->plus == 1)
	{
		char_count += ft_putchar('+');
		flags->width--;
	}
	char_count += ft_print_width(flags->dot, ft_strlen(str), 1);
	char_count += ft_print_prec(ft_strlen(str), str);
	return (char_count);
}

static int		ft_isminus(t_flags *flags, char *str, long int d_i)
{
	int char_count;

	char_count = 0;
	if (d_i < 0)
	{
		char_count += ft_putchar('-');
		flags->width--;
	}
	else if (d_i >= 0 && flags->plus == 1)
	{
		char_count += ft_putchar('+');
		flags->width--;
	}
	if (flags->dot >= 0)
		char_count += ft_print_width(flags->dot - 1, ft_strlen(str) - 1, 1);
	char_count += ft_print_prec(ft_strlen(str), str);
	char_count += ft_print_width(flags->width, flags->dot, 0);
	return (char_count);
}

int				ft_isint(t_flags *flags, long int d_i)
{
	int		char_count;
	char	*str;

	char_count = 0;
	if (flags->dot == 0 && d_i == 0 && flags->plus == 0)
	{
		char_count += ft_print_width(flags->width, 0, 0);
		return (char_count);
	}
	if (d_i == 0 && flags->dot != 0)
		str = ft_strdup("0");
	else
		str = ft_itoa(d_i, 10);
	if (flags->dot >= 0 || flags->minus == 1)
		flags->zero = 0;
	if (flags->dot <= ft_strlen(str))
		flags->dot = ft_strlen(str);
	if (flags->minus == 1)
		char_count += ft_isminus(flags, str, d_i);
	if (flags->minus == 0 && flags->zero == 0)
		char_count += ft_isminuszero(flags, str, d_i);
	if (flags->minus == 0 && flags->zero == 1)
		char_count += ft_isminuszero1(flags, str, d_i);
	free(str);
	return (char_count);
}
