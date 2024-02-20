/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:33:31 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/08 19:35:56 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/r2_lib.h"

int	first_not_triplet(char *nbr, t_print_num *num, t_mat_row_num mat_row, int i)
{
	int		first_trip;
	char	dest[4];

	first_trip = get_str_len(nbr) % 3;
	if (first_trip)
	{
		create_triplet(nbr, i, dest);
		if (ft_strcmp("000", dest))
		{
			add_to_output(num, get_string_triplet(dest, mat_row.mat));
			num->output_index += 1;
			add_to_output(num, find_ten_power(nbr, i + first_trip, mat_row));
			num->output_index += 1;
			return (1);
		}
	}
	return (0);
}

void	get_rest(int *i, char *nbr, t_print_num *num, t_mat_row_num mat_row)
{
	char	dest[4];
	int		first_trip;

	first_trip = get_str_len(nbr) % 3;
	while (*i < first_trip)
		*i += 1;
	while (*i < get_str_len(nbr) - 3)
	{
		create_triplet(nbr, *i, dest);
		if (ft_strcmp("000", dest))
		{
			add_to_output(num, get_string_triplet(dest, mat_row.mat));
			*i += 3;
			add_to_output(num, find_ten_power(nbr, *i, mat_row));
		}
		else
			*i += 3;
	}
	create_triplet(nbr, *i, dest);
	add_to_output(num, get_string_triplet(dest, mat_row.mat));
	print_result(num);
}

void	print_number(char *nbr, t_mat_row_num mat_row)
{
	int			i;
	int			first_trip;
	t_print_num	num;

	num.output_index = 0;
	if (number_empty(nbr))
		return ;
	if (number_less_than_4_digits(nbr, mat_row))
		return ;
	i = 0;
	num.output_index = 0;
	i += only_triplets(nbr, &num, mat_row);
	first_trip = get_str_len(nbr) % 3;
	if (first_trip != 2)
		while (i < first_trip - 1)
			i++;
	first_not_triplet(nbr, &num, mat_row, i);
	get_rest(&i, nbr, &num, mat_row);
}
