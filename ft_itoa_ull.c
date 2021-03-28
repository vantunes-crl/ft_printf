/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ull.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantunes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 13:26:04 by vantunes          #+#    #+#             */
/*   Updated: 2021/03/28 13:26:06 by vantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_lenofnum(unsigned long long i, int base)
{
	int count;

	count = 0;
	while (i > 0)
	{
		i /= base;
		count++;
	}
	return (count);
}

char			*ft_itoa_ull(unsigned long long ull, int base)
{
	char	*rtn;
	int		len;

	if (ull == 0)
	{
		rtn = ft_strdup("0");
		return (rtn);
	}
	rtn = (char *)malloc(sizeof(char) * (ft_lenofnum(ull, base) + 1));
	if (!rtn)
		return (0);
	len = ft_lenofnum(ull, base);
	rtn[len--] = '\0';
	while (ull > 0)
	{
		if ((ull % base) < 10)
			rtn[len] = (ull % base) + 48;
		else
			rtn[len] = (ull % base) + 55;
		len--;
		ull /= base;
	}
	return (rtn);
}
