/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaudio <fgaudio@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:52:52 by fgaudio           #+#    #+#             */
/*   Updated: 2024/02/25 18:05:28 by fgaudio          ###   ########.fr       */
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

static char	*gen_mod_dup(const char *s, char c)
{
	char	*trim;
	int		i[2];
	char	set[2];

	set[0] = c;
	set[1] = '\0';
	trim = ft_strtrim(s, set);
	i[0] = 0;
	while (trim[i[0]])
	{
		i[1] = i[0];
		if (trim[i[0] + 1] == trim[i[0]] && trim[i[0]] == c)
			while (trim[++i[1]])
				trim[i[1]] = trim[i[1] + 1];
		else
			i[0]++;
	}
	return (trim);
}

char	**ft_split(char const *s, char c)
{
	int		nstrings;
	char	*scpy;
	char	**ret;

	if (!s)
		return (NULL);
	scpy = gen_mod_dup(s, c);
	if (!scpy)
		return (NULL);
	if (!*scpy)
	{
		free(scpy);
		return (ft_calloc(1, sizeof(char *)));
	}
	nstrings = 1;
	while (ft_strrchr(scpy, c) && c)
	{
		*ft_strrchr(scpy, c) = '\0';
		nstrings++;
	}
	ret = gen_array(nstrings, scpy);
	free(scpy);
	return (ret);
}
