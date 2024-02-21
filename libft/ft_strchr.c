/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaudio <fgaudio@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:34:46 by fgaudio           #+#    #+#             */
/*   Updated: 2024/02/21 21:34:46 by fgaudio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;
	char	f;

	tmp = (char *)s;
	f = (unsigned char)c;
	while (*tmp)
	{
		if (*tmp == f)
			return (tmp);
		tmp++;
	}
	if (*tmp == f)
		return (tmp);
	return (0);
}
