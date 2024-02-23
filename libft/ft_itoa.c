/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaudio <fgaudio@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:06:31 by fgaudio           #+#    #+#             */
/*   Updated: 2024/02/23 14:40:58 by fgaudio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_res(int ndigits, int neg, long pos)
{
	char	*res;

	res = ft_calloc(ndigits + 1 + neg, sizeof(char));
	if (!res)
		return (NULL);
	if (neg)
		res[0] = '-';
	while (--ndigits >= 0)
	{
		res[ndigits + neg] = pos % 10 + '0';
		pos /= 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	int		ndigits;
	long	tmp;
	int		neg;

	tmp = n;
	ndigits = 1;
	while (tmp / 10 != 0)
	{
		ndigits++;
		tmp /= 10;
	}
	if (n < 0)
	{
		neg = 1;
		tmp = -(long)n;
	}
	else
	{
		neg = 0;
		tmp = n;
	}
	return (get_res(ndigits, neg, tmp));
}
