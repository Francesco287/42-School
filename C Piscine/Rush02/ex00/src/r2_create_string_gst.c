/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r2_create_string_gst.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:51:46 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/08 22:30:32 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/r2_lib.h"

void	init_create_string_gst_val(int *i, char **ret, int *k)
{
	*i = -1;
	*ret = malloc(1000);
	*k = 0;
}

void	set_j_set_ret(char *hundred, char **ret, int *k, int i)
{
	int	j;

	if (i == 0)
	{
		j = -1;
		while (hundred[++j])
		{
			(*ret)[*k] = hundred[j];
			*k += 1;
		}
	}
}

char	*create_string_gst(int keys[3], int hdu[3], char ***mat)
{
	char	*ret;
	int		i;
	int		j;
	int		k;
	char	*hundred;

	hundred = "hundred ";
	init_create_string_gst_val(&i, &ret, &k);
	while (++i < 3)
	{
		j = -1;
		if (hdu[i])
		{
			while (mat[keys[i]][1][++j])
				ret[k++] = mat[keys[i]][1][j];
			ret[k++] = ' ';
			set_j_set_ret(hundred, &ret, &k, i);
		}
	}
	ret[--k] = '\0';
	return (ret);
}
