/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r2_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:15:51 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/08 20:16:39 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef R2_LIB_H
# define R2_LIB_H
# include "mat_row_num.h"
# include "print_number_strct.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

int		count_def_len(int file);
int		*get_def_len_arr(const char *file_name, int row_num);
int		get_file_size(const char *path);
int		count_row_num(const char *path);
int		*count_nbr_char(const char *path);
char	***generate_matrix(const char *path);
void	get_num_def(int file, char ***mat, int row_num);
int		ft_strcmp(char *s1, char *s2);
char	*find_num(char *num, t_mat_row_num mat_row);
void	get_num(int file, char ***mat, int row_num);
void	fill_matrix(const char *file_name, char ***matrix, int row_num);
int		get_str_len(char *str);
char	*find_ten_power(char *nbr, int i, t_mat_row_num mat_row);
void	put_str(char *str);
void	create_triplet(char *nbr, int i, char dest[4]);
void	add_to_output(t_print_num *num, char *str);
void	print_result(t_print_num *num);
int		empty(char *str);
void	print_number(char *nbr, t_mat_row_num mat_row);
char	*create_string_gst(int keys[3], int hdu[3], char ***mat);
char	*get_string_triplet(char *triplet, char ***mat);
int		number_empty(char *nbr);
int		number_less_than_4_digits(char *nbr, t_mat_row_num mat_row);
int		only_triplets(char *nbr, t_print_num *num, t_mat_row_num mat_row);
char	*parse_input(char *str);
#endif
