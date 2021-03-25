/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantunes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:40:47 by vantunes          #+#    #+#             */
/*   Updated: 2021/03/22 15:40:51 by vantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ischar(t_flags *flags, va_list args)
{
	int char_count;

	char_count = 0;
	if (flags->minus == 1)
	{
		char_count = ft_putchar(va_arg(args, int));
		char_count += ft_print_width(flags->width, 1, 0);
	}
	else if (flags->minus == 0)
	{
		char_count += ft_print_width(flags->width, 1, 0);
		char_count += ft_putchar(va_arg(args, int));
	}
	return (char_count);
}
