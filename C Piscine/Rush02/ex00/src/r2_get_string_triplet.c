/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r2_get_string_triplet.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 22:28:22 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/08 23:14:15 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/r2_lib.h"

int	aux1(char *triplet, int hdu[3], int i)
{
	if (triplet[i] == '0')
	{
		hdu[i] = 0;
		return (1);
	}
	else
		hdu[i] = 1;
	return (0);
}

void	aux2(char *triplet, int i, int keys[3], char ***mat)
{
	int		j;
	char	t[3];

	t[0] = triplet[i];
	t[1] = '\0';
	j = 0;
	while (ft_strcmp(t, mat[j][0]))
		j++;
	keys[i] = j;
}

void	aux3(char *triplet, int keys[3], int i, char ***mat)
{
	char	t[3];
	int		j;

	t[0] = triplet[i];
	t[1] = '0';
	t[2] = '\0';
	j = 0;
	while (ft_strcmp(t, mat[j][0]))
		j++;
	keys[i] = j;
}

void	aux4(char *triplet, int i, char ***mat, int keys[3])
{
	char	t[3];
	int		j;

	t[0] = triplet[i];
	t[1] = triplet[i + 1];
	t[2] = '\0';
	j = 0;
	while (ft_strcmp(t, mat[j][0]))
		j++;
	keys[i] = j;
}

char	*get_string_triplet(char *triplet, char ***mat)
{
	int		keys[3];
	int		hdu[3];
	int		i;

	i = -1;
	while (++i < 3)
	{
		if (aux1(triplet, hdu, i))
			continue ;
		if (i == 0 || i == 2)
			aux2(triplet, i, keys, mat);
		if (i == 1)
		{
			if (triplet[i] == '1')
			{
				aux4(triplet, i, mat, keys);
				hdu[2] = 0;
				break ;
			}
			else
				aux3(triplet, keys, i, mat);
		}
	}
	return (create_string_gst(keys, hdu, mat));
}
