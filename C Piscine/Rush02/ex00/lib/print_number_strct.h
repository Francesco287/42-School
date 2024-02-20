/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number_strct.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:38:27 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/08 19:38:28 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_NUMBER_STRCT_H
# define PRINT_NUMBER_STRCT_H

typedef struct print_number_strct
{
	char	output[64][1024];
	int		output_index;
}	t_print_num;
#endif
