/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantunes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 13:23:03 by vantunes          #+#    #+#             */
/*   Updated: 2021/03/28 13:23:05 by vantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_isdot(t_flags *flags, va_list args, const char *str, int pos)
{
	pos++;
	if (str[pos] == '*')
	{
		flags->dot = va_arg(args, int);
		pos++;
	}
	else
	{
		flags->dot = 0;
		while (ft_isdigit(str[pos]))
			flags->dot = (flags->dot * 10) + (str[pos++] - 48);
	}
	return (pos);
}

t_flags		*ft_isminus(t_flags *flags)
{
	flags->minus = 1;
	flags->zero = 0;
	return (flags);
}

t_flags		ft_init_flags(void)
{
	t_flags flags;

	flags.dot = -1;
	flags.minus = 0;
	flags.star = 0;
	flags.width = 0;
	flags.zero = 0;
	flags.type = 0;
	flags.plus = 0;
	return (flags);
}

t_flags		*ft_isstar(t_flags *flags, va_list args)
{
	flags->star = 1;
	flags->width = va_arg(args, int);
	if (flags->width < 0)
	{
		flags->width *= -1;
		flags->minus = 1;
	}
	return (flags);
}

t_flags		*ft_digitflag(t_flags *flags, char c)
{
	if (flags->star == 1)
		flags->width = 0;
	flags->width = (flags->width * 10) + (c - 48);
	return (flags);
}
