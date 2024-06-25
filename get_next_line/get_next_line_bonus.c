/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaudio <fgaudio@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 00:39:08 by fgaudio           #+#    #+#             */
/*   Updated: 2024/06/25 18:19:04 by fgaudio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	get_next_char(int fd, char **buffer, int i)
{
	static char	*s_buf[OPEN_MAX][2];
	int			refill_return;

	if (s_buf[fd][0] == NULL)
	{
		s_buf[fd][0] = malloc(BUFFER_SIZE + 1);
		s_buf[fd][0][BUFFER_SIZE] = '\0';
		s_buf[fd][1] = s_buf[fd][0] + BUFFER_SIZE;
		if (s_buf[fd][0] == NULL)
			return (-1);
	}
	if (!*(s_buf[fd][1]))
	{
		refill_return = refill(&(s_buf[fd]), fd);
		if (refill_return != 1)
		{
			free(s_buf[fd][0]);
			s_buf[fd][0] = NULL;
			return (refill_return);
		}
	}
	if (add_one(buffer, i))
		return (-1);
	(*buffer)[i] = *(s_buf[fd][1]++);
	return (1);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	int		i;
	int		err_check;

	if (fd < 0 || BUFFER_SIZE <= 0 || OPEN_MAX < 0)
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
