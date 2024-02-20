/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_row_num.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:36:40 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/08 19:37:48 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAT_ROW_NUM_H
# define MAT_ROW_NUM_H

typedef struct mat_row_num {
	char	***mat;
	int		row_nb;
}	t_mat_row_num;

// Function prototype declaration
t_mat_row_num	init_mat_row_num(char ***new_mat, int new_row_nb);

#endif
