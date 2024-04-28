/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaudio <fgaudio@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 00:39:04 by fgaudio           #+#    #+#             */
/*   Updated: 2024/04/28 15:16:44 by fgaudio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	str_cpy(char *dest, const char *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
}

int	add_one(char **str, int i)
{
	char	*tmp;

	if (i == 0)
	{
		*str = malloc(1);
		if (*str == NULL)
			return (1);
		return (0);
	}
	tmp = malloc(i);
	if (tmp == NULL)
		return (1);
	str_cpy(tmp, *str, i);
	free(*str);
	*str = malloc(i + 1);
	if (*str == NULL)
		return (1);
	str_cpy(*str, tmp, i);
	free(tmp);
	return (0);
}

int	get_next_char(int fd, char **buffer, int i)
{
	static void	*s_buf[3];

	if (s_buf[0] == NULL)
	{
		s_buf[0] = malloc(BUFFER_SIZE * sizeof(char));
		s_buf[1] = s_buf[0] + BUFFER_SIZE;
		s_buf[2] = malloc(1 * sizeof(int));
		if (s_buf[0] == NULL || s_buf[2] == NULL)
			return (-1);
	}
	if (s_buf[1] - s_buf[0] == BUFFER_SIZE)
	{
		*((int *)s_buf[2]) = read(fd, (char *)s_buf[0], BUFFER_SIZE);
		if (*((int *)s_buf[2]) == 0)
			return (0);
		s_buf[1] = s_buf[0];
	}
	if (s_buf[1] - s_buf[0] == *((int *)s_buf[2]))
		return (0);
	if (*((int *)s_buf[2]) == -1)
		return (-1);
	if (add_one(buffer, i))
		return (-1);
	(*buffer)[i] = *((char *)(s_buf[1]++));
	return (1);
}
