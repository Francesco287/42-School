/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:21:12 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/08 19:21:35 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/r2_lib.h"

char	*find_num(char *num, t_mat_row_num mat_row)
{
	char	*s1;
	int		i;

	i = 0;
	while (i < mat_row.row_nb)
	{
		s1 = mat_row.mat[i][0];
		if (!ft_strcmp(s1, num))
			return (mat_row.mat[i][1]);
		i++;
	}
	return (NULL);
}
