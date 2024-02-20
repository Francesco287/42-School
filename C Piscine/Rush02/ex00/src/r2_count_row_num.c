/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_row_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:17:35 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/08 19:17:36 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/r2_lib.h" 

int	count_row_num(const char *path)
{
	int		file;
	int		row_num;
	char	buffer;

	row_num = 0;
	file = open(path, O_RDONLY);
	while (read(file, &buffer, 1))
		if (buffer == '\n')
			row_num++;
	close(file);
	return (row_num + 1);
}
