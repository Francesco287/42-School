/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaudio <fgaudio@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:35:14 by fgaudio           #+#    #+#             */
/*   Updated: 2024/02/21 21:35:14 by fgaudio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		slen;
	char	*dup;

	slen = ft_strlen(s) + 1;
	dup = (char *)malloc(slen);
	if (!dup)
		return (0);
	ft_memcpy(dup, s, slen);
	return (dup);
}
