/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantunes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:36:34 by vantunes          #+#    #+#             */
/*   Updated: 2021/03/22 15:36:35 by vantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_prec(int prec, char *str)
{
	int char_count;
	int i;

	i = 0;
	char_count = 0;
	while (str[i] && i < prec)
	{
		ft_putchar(str[i]);
		i++;
		char_count++;
	}
	return (char_count);
}

char	*ft_tolower_str(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*rtn;

	i = 0;
	rtn = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!rtn)
		return (0);
	while (str[i])
	{
		rtn[i] = str[i];
		i++;
	}
	return (rtn);
}
