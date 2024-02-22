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

static char	**gen_array(int nstrings, char *scpy)
{
	int		counters[2];
	char	**res;

	res = ft_calloc(nstrings + 1, sizeof(char *));
	if (!res)
		return (NULL);
	counters[0] = -1;
	while (++counters[0] < nstrings)
	{
		res[counters[0]] = ft_calloc(ft_strlen(scpy) + 1, sizeof(char));
		if (!res[counters[0]])
			return (NULL);
		counters[1] = 0;
		while (*scpy)
			res[counters[0]][counters[1]++] = *scpy++;
		scpy++;
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	int		nstrings;
	char	*scpy;
	char	**ret;

	if (!s)
		return (NULL);
	scpy = ft_strdup(s);
	if (!scpy)
		return (NULL);
	nstrings = 1;
	while (ft_strrchr(scpy, c))
	{
		*ft_strrchr(scpy, c) = '\0';
		nstrings++;
	}
	ret = gen_array(nstrings, scpy);
	free(scpy);
	return (ret);
}
