/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaudio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:14:52 by fgaudio           #+#    #+#             */
/*   Updated: 2023/10/10 20:15:24 by fgaudio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*ret;

	len = 0;
	while (src[len])
		len++;
	ret = malloc(len + 1);
	i = 0;
	while (i < len)
	{
		ret[i] = src[i];
		i++;
	}
	ret[len] = '\0';
	return (ret);
}
