/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaudio <fgaudio@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 00:39:04 by fgaudio           #+#    #+#             */
/*   Updated: 2024/06/25 18:10:05 by fgaudio          ###   ########.fr       */
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

int	refill(char *(*s_buf)[2], int fd)
{
	int			chr_read;
	char		*tmp;

	tmp = malloc(BUFFER_SIZE);
	if (tmp == NULL)
		return (-1);
	chr_read = read(fd, tmp, BUFFER_SIZE);
	if (chr_read == 0 || chr_read == -1)
	{
		free(tmp);
		return (chr_read);
	}
	str_cpy((*s_buf)[0], tmp, chr_read);
	free(tmp);
	if (chr_read != BUFFER_SIZE)
		if (free_unused(&((*s_buf)[0]), chr_read + 1))
			return (-1);
	(*s_buf)[0][chr_read] = '\0';
	(*s_buf)[1] = (*s_buf)[0];
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
