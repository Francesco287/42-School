/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:27:10 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/08 19:29:08 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/r2_lib.h"

int	get_file_size(const char *path)
{
	int		file;
	int		len;
	char	buffer;

	len = 0;
	file = open(path, O_RDONLY);
	while (read(file, &buffer, 1))
		len++;
	close(file);
	return (len);
}
