/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_row_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:31:38 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/08 19:32:33 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/r2_lib.h"

// Function definition
t_mat_row_num	init_mat_row_num(char ***new_mat, int new_row_nb)
{
	t_mat_row_num	instance;

	instance.mat = new_mat;
	instance.row_nb = new_row_nb;
	return (instance);
}
