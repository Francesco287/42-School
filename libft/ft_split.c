/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaudio <fgaudio@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:52:52 by fgaudio           #+#    #+#             */
/*   Updated: 2024/02/22 19:54:25 by fgaudio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	int		nstrings;
	char	*scpy;
	char	**res;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	scpy = ft_calloc(ft_strlen(s), sizeof(char));
	if (!scpy)
		return (NULL);
	ft_strlcpy(scpy, s, ft_strlen(s) + 1);
	nstrings = 1;
	while (ft_strrchr(scpy, c))
	{
		*ft_strrchr(scpy, c) = '\0';
		nstrings++;
	}
	res = ft_calloc(nstrings + 1, sizeof(char *));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < nstrings)
	{
		res[i] = ft_calloc(ft_strlen(scpy) + 1, sizeof(char));
		if (!res[i])
			return (NULL);
		j = -1;
		while(*scpy)
			res[i][++j] = *scpy++;
		scpy++;
	}
	return (res);
}
