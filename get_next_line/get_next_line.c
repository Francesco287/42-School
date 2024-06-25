/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaudio <fgaudio@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 00:39:08 by fgaudio           #+#    #+#             */
/*   Updated: 2024/06/25 18:18:10 by fgaudio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_char(int fd, char **buffer, int i)
{
	static char	*s_buf[2];
	int			refill_return;

	if (s_buf[0] == NULL)
	{
		s_buf[0] = malloc(BUFFER_SIZE + 1);
		s_buf[0][BUFFER_SIZE] = '\0';
		s_buf[1] = s_buf[0] + BUFFER_SIZE;
		if (s_buf[0] == NULL)
			return (-1);
	}
	if (!*(s_buf[1]))
	{
		refill_return = refill(&s_buf, fd);
		if (refill_return != 1)
		{
			free(s_buf[0]);
			s_buf[0] = NULL;
			return (refill_return);
		}
	}
	if (add_one(buffer, i))
		return (-1);
	(*buffer)[i] = *(s_buf[1]++);
	return (1);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	int		i;
	int		err_check;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	err_check = get_next_char(fd, &buffer, i);
	while (err_check)
	{
		if (err_check == -1)
			return (NULL);
		if (buffer[i++] == '\n')
			break ;
		err_check = get_next_char(fd, &buffer, i);
	}
	if (i == 0)
		return (NULL);
	add_one(&buffer, i);
	buffer[i++] = '\0';
	if (free_unused(&buffer, i))
		return (NULL);
	return (buffer);
}
