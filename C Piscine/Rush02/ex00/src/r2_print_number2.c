/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:43:31 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/08 19:43:32 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/r2_lib.h"

int	number_empty(char *nbr)
{
	if (empty(nbr))
	{
		put_str("zero");
		return (1);
	}
	return (0);
}

int	number_less_than_4_digits(char *nbr, t_mat_row_num mat_row)
{
	char		dest[4];
	t_print_num	num;
	int			i;

	i = 0;
	num.output_index = 0;
	if (get_str_len(nbr) < 4)
	{
		create_triplet(nbr, i, dest);
		if (ft_strcmp("000", dest))
		{
			add_to_output(&num, get_string_triplet(dest, mat_row.mat));
			print_result(&num);
		}
		return (1);
	}
	return (0);
}

int	only_triplets(char *nbr, t_print_num *num, t_mat_row_num mat_row)
{
	char	dest[4];
	int		first_trip;
	int		i;

	i = 0;
	first_trip = get_str_len(nbr) % 3;
	if (!first_trip)
	{
		create_triplet(nbr, i, dest);
		if (ft_strcmp("000", dest))
		{
			add_to_output(num, get_string_triplet(dest, mat_row.mat));
			num->output_index += 1;
			i += 3;
			add_to_output(num, find_ten_power(nbr, i, mat_row));
			num->output_index += 1;
			return (i);
		}
	}
	return (0);
}
