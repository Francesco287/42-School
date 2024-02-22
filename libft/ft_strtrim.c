/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaudio <fgaudio@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:19:06 by fgaudio           #+#    #+#             */
/*   Updated: 2024/02/22 19:07:32 by fgaudio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	char	*res;
	int		i;
	int		j;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	while (--len >= 0)
		if (!ft_strchr(set, s1[len]))
			break ;
	i = -1;
	while (++i < len)
		if (!ft_strchr(set, s1[i]))
			break ;
	res = ft_calloc(len - i + 2, sizeof(char));
	if (!res)
		return (NULL);
	j = 0;
	while (i <= len)
	{
		res[j++] = s1[i];
		i++;
	}
	return (res);
}
