/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantunes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 13:25:29 by vantunes          #+#    #+#             */
/*   Updated: 2021/03/28 13:25:34 by vantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_lenofnum(long int i, int base)
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

char			*ft_itoa(long int i, int base)
{
	char	*rtn;
	int		j;

	if (i < 0)
		i *= -1;
	rtn = (char *)malloc(sizeof(char) * (ft_lenofnum(i, base)));
	if (!rtn)
		return (0);
	j = ft_lenofnum(i, base);
	rtn[j--] = '\0';
	while (i > 0)
	{
		rtn[j--] = (i % base) + 48;
		i /= base;
	}
	return (rtn);
}
