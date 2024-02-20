/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaudio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:18:28 by fgaudio           #+#    #+#             */
/*   Updated: 2023/10/10 20:18:46 by fgaudio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	fill_string(int size, char **strs, char *sep, char *ret)
{
	int	i;
	int	j;
	int	k;

	k = -1;
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (strs[i][++j])
			ret[++k] = strs[i][j];
		if (i == size - 1)
			break ;
		j = -1;
		while (sep[++j])
			ret[++k] = sep[j];
	}
	ret[++k] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ret;
	int		s[2];
	int		i;
	int		j;

	if (!size)
	{
		ret = malloc(1);
		ret[0] = '\0';
		return (ret);
	}
	i = -1;
	s[0] = 0;
	while (++i < size)
	{
		j = -1;
		while (strs[i][++j])
			s[0]++;
	}
	s[1] = 0;
	while (sep[s[1]])
		s[1]++;
	ret = malloc(s[0] + (size - 1) * s[1] + 1);
	fill_string(size, strs, sep, ret);
	return (ret);
}
