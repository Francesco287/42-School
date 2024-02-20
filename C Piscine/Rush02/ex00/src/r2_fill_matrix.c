/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:20:49 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/08 19:20:57 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/r2_lib.h" 

void	fill_matrix(const char *file_name, char ***matrix, int row_num)
{
	int	file;

	file = open(file_name, O_RDONLY);
	get_num(file, matrix, row_num);
	file = open(file_name, O_RDONLY);
	get_num_def(file, matrix, row_num);
}
