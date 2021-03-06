/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_type_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantunes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 13:24:16 by vantunes          #+#    #+#             */
/*   Updated: 2021/03/28 13:24:20 by vantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ispercent(t_flags *flags)
{
	int char_count;

	char_count = 0;
	if (flags->minus == 1 || flags->dot >= 0)
		flags->zero = 0;
	if (flags->minus == 1)
	{
		char_count += ft_putchar('%');
		char_count += ft_print_width(flags->width, 1, 0);
	}
	if (flags->minus == 0 && flags->zero == 0)
	{
		char_count += ft_print_width(flags->width, 1, 0);
		char_count += ft_putchar('%');
	}
	if (flags->zero == 1)
	{
		char_count += ft_print_width(flags->width, 1, 1);
		char_count += ft_putchar('%');
	}
	return (char_count);
}
