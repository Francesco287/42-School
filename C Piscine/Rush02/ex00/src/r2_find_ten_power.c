/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ten_power.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:23:15 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/08 19:23:18 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/r2_lib.h" 

char	*find_ten_power(char *nbr, int i, t_mat_row_num mat_row)
{
	int		pow;
	int		j;
	char	*str;

	pow = 1;
	while (nbr[i])
	{
		i++;
		pow++;
	}
	str = malloc(pow + 1);
	j = 0;
	while (j < pow)
	{
		if (j == 0)
			str[j] = '1';
		else
			str[j] = '0';
		j++;
	}
	str[j] = '\0';
	return (find_num(str, mat_row));
}
