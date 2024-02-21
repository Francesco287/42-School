/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaudio <fgaudio@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:38:11 by fgaudio           #+#    #+#             */
/*   Updated: 2024/02/21 21:38:11 by fgaudio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	char	f;
	char	last_occ;

	last_occ = 0;
	tmp = (char *)s;
	f = (unsigned char)c;
	while (*tmp)
	{
		if (*tmp == f)
			last_occ = tmp;
		tmp++;
	}
	if (*tmp == f)
		last_occ = tmp;
	return (last_occ);
}
