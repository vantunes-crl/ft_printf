/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantunes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:36:58 by vantunes          #+#    #+#             */
/*   Updated: 2021/03/23 15:59:58 by vantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_printpointer(t_flags *flags, char *pointer)
{
	int char_count;

	char_count = 0;
	char_count += ft_print_prec(2, "0x");
	char_count += ft_print_prec(ft_strlen(pointer), pointer);
	char_count += ft_print_width(flags->width, ft_strlen(pointer) + 2, 0);
	return (char_count);
}

int				ft_ispointer(t_flags *flags, unsigned long long ull)
{
	char	*pointer;
	int		char_count;

	char_count = 0;
	if (ull == 0 && flags->dot >= 0)
	{
		char_count += ft_print_width(flags->width, 2, 0);
		char_count += ft_print_prec(2, "0x");
		char_count += ft_print_width(flags->dot, 0, 1);
		return (char_count);
	}
	pointer = ft_itoa_ull(ull, 16);
	pointer = ft_tolower_str(pointer);
	if (flags->minus == 1)
		char_count += ft_printpointer(flags, pointer);
	if (flags->minus == 0)
	{
		char_count += ft_print_width(flags->width, ft_strlen(pointer) + 2, 0);
		char_count += ft_print_prec(2, "0x");
		char_count += ft_print_width(flags->dot, ft_strlen(pointer), 1);
		char_count += ft_print_prec(ft_strlen(pointer), pointer);
	}
	free(pointer);
	return (char_count);
}
