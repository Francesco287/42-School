/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:24:37 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/08 19:25:04 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/r2_lib.h"

char	***generate_matrix(const char *path)
{
	char	***mat;
	int		row_nb;
	int		*char_lens[2];
	int		i;

	row_nb = count_row_num(path);
	char_lens[0] = count_nbr_char(path);
	if (!char_lens[0])
		return (0);
	char_lens[1] = get_def_len_arr(path, row_nb);
	if (!char_lens[1])
		return (0);
	mat = malloc(row_nb * sizeof(char **));
	i = -1;
	while (++i < row_nb)
	{
		mat[i] = malloc(2 * sizeof(char *));
		mat[i][0] = malloc(char_lens[0][i] + 1);
		mat[i][1] = malloc(char_lens[1][i] + 1);
	}
	free(char_lens[0]);
	free(char_lens[1]);
	return (mat);
}
