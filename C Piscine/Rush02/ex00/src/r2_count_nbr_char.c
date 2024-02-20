/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_nbr_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:17:04 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/08 19:17:18 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/r2_lib.h" 

int	*count_nbr_char(const char *path)
{
	int		file;
	char	buffer;
	int		tmp;
	int		*ret;
	int		i;

	i = 0;
	ret = malloc(count_row_num(path) * sizeof(int));
	tmp = 0;
	file = open(path, O_RDONLY);
	if (file == -1)
		return (0);
	while (read(file, &buffer, 1))
	{
		if (buffer >= '0' && buffer <= '9')
			tmp++;
		else if (buffer == ':')
		{
			ret[i++] = tmp;
			tmp = 0;
		}
	}
	close(file);
	return (ret);
}
