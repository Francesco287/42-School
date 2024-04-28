/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaudio <fgaudio@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 00:39:04 by fgaudio           #+#    #+#             */
/*   Updated: 2024/04/29 00:05:17 by fgaudio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

void	*mod_malloc(size_t nmemb)
{
	void	*ptr;
	size_t	i;

	ptr = malloc(nmemb);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < nmemb)
	{
		((unsigned char *)ptr)[i] = '1';
		i++;
	}
	return (ptr);
}

int	add_one(char **str, int i)
{
	char	*tmp;

	if (i == 0)
	{
		*str = mod_malloc(ADD_ONE_BUFFER);
		if (*str == NULL)
			return (1);
		(*str)[ADD_ONE_BUFFER - 1] = '\0';
		return (0);
	}
	if ((*str)[i] != '\0')
		return (0);
	tmp = mod_malloc(i);
	if (tmp == NULL)
		return (1);
	str_cpy(tmp, *str, i);
	free(*str);
	*str = mod_malloc(i + ADD_ONE_BUFFER);
	if (*str == NULL)
		return (1);
	str_cpy(*str, tmp, i);
	free(tmp);
	(*str)[i + ADD_ONE_BUFFER - 1] = '\0';
	return (0);
}

int	get_next_char(int fd, char **buffer, int i)
{
	static void	*s_buf[OPEN_MAX][3];

	if (s_buf[fd][0] == NULL)
	{
		s_buf[fd][0] = malloc(BUFFER_SIZE * sizeof(char));
		s_buf[fd][1] = s_buf[fd][0] + BUFFER_SIZE;
		s_buf[fd][2] = malloc(1 * sizeof(int));
		if (s_buf[fd][0] == NULL || s_buf[fd][2] == NULL)
			return (-1);
	}
	if (s_buf[fd][1] - s_buf[fd][0] == BUFFER_SIZE)
	{
		*((int *)s_buf[fd][2]) = read(fd, (char *)s_buf[fd][0], BUFFER_SIZE);
		if (*((int *)s_buf[fd][2]) == 0)
			return (0);
		s_buf[fd][1] = s_buf[fd][0];
	}
	if (s_buf[fd][1] - s_buf[fd][0] == *((int *)s_buf[fd][2]))
		return (0);
	if (*((int *)s_buf[fd][2]) == -1)
		return (-1);
	if (add_one(buffer, i))
		return (-1);
	(*buffer)[i] = *((char *)(s_buf[fd][1]++));
	return (1);
}

int	free_unused(char **str, int i)
{
	char	*tmp;

	tmp = malloc(i);
	if (tmp == NULL)
		return (1);
	str_cpy(tmp, *str, i);
	free(*str);
	*str = tmp;
	return (0);
}
