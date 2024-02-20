/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:12:29 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/08 20:41:11 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/r2_lib.h"

void	add_to_output(t_print_num *num, char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		num->output[num->output_index][0] = '0';
		num->output_index++;
		return ;
	}
	while (str[i])
	{
		num->output[num->output_index][i] = str[i];
		i++;
	}
	num->output_index++;
}
