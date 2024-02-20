/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:36:11 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/08 19:36:28 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/r2_lib.h"

int	dict_error(t_print_num *num)
{
	int	i;

	i = 0;
	while (i < num->output_index)
	{
		if (num->output[i][0] == '0')
			return (1);
		i++;
	}
	return (0);
}

void	print_result(t_print_num *num)
{
	int	i;

	if (dict_error(num))
	{
		put_str("Dict Error\n");
		return ;
	}
	i = 0;
	while (i < num->output_index)
	{
		put_str(num->output[i]);
		if (!(i % 2))
			put_str(" ");
		i++;
	}
}
