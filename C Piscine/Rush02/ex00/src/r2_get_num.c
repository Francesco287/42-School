/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:29:24 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/08 19:29:48 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/r2_lib.h"

void	get_num(int file, char ***mat, int row_num)
{
	int		i;
	int		num;
	char	buff;
	int		ignoring;

	i = 0;
	num = 0;
	ignoring = 0;
	while (read(file, &buff, 1))
	{
		if (buff == '\n')
		{
			if (ignoring)
				mat[i++][0][num] = '\0';
			ignoring = 0;
			num = 0;
		}
		if (buff == ':')
			ignoring = 1;
		if (!ignoring && buff != ' ' && buff != '\n')
			mat[i][0][num++] = buff;
	}
	close(file);
}
