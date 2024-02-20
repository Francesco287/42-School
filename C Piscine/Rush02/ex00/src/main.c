/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:07:26 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/08 19:11:49 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/r2_lib.h" 

/***
 * TODO: LIST
 * 2. Protect when value wasn't found in the dictionary ?
 * 3. Check if memory is freed when not needed ?
***/

int	reassign_main_values(char **dict_path, char **number, int argc, char **argv)
{
	*dict_path = "numbers.dict";
	if (argc == 2)
		*number = argv[1];
	else if (argc == 3)
	{
		*number = argv[2];
		*dict_path = argv[1];
	}
	else
		return (0);
	return (1);
}

int	file_exists(const char *dict_path)
{
	int	file;

	file = open(dict_path, O_RDONLY);
	if (file == -1)
		return (0);
	else
		return (1);
}

int	main(int argc, char **argv)
{
	char			*dict_path;
	char			*number;
	char			***mat;

	if (!reassign_main_values(&dict_path, &number, argc, argv))
		return (0);
	number = parse_input(number);
	if (number == -2)
	{
		put_str("Error\n");
		return (0);
	}
	else if (number == -1)
		number = "0";
	else if (number == -3)
		return (0);
	if (!file_exists(dict_path))
		return (0);
	mat = generate_matrix(dict_path);
	fill_matrix(dict_path, mat, count_row_num(dict_path));
	print_number(number, init_mat_row_num(mat, count_row_num(dict_path)));
	return (0);
}
