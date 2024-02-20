/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_def_len_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:25:31 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/08 19:26:16 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/r2_lib.h"

void	find_end(int *row_len, int file, int row_num)
{
	int	temp_count;

	temp_count = 0;
	while (!(*row_len))
	{
		*row_len = count_def_len(file);
		temp_count++;
		if (temp_count > row_num)
			break ;
	}
}

int	*get_def_len_arr(const char *file_name, int row_num)
{
	int	*rows_def;
	int	file;
	int	i;
	int	row_len;

	i = 0;
	file = open(file_name, O_RDONLY);
	if (file == -1)
		return (0);
	rows_def = (int *)malloc(row_num * sizeof(int));
	while (i < row_num)
	{
		row_len = count_def_len(file);
		find_end(&row_len, file, row_num);
		rows_def[i] = row_len;
		i++;
	}
	close(file);
	return (rows_def);
}
