/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaudio <fgaudio@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 22:28:45 by fgaudio           #+#    #+#             */
/*   Updated: 2024/06/23 17:16:10 by fgaudio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *strl)
{
	int		i;
	char	*str;

	i = 0;
	if (!strl[i])
		return (NULL);
	while (strl[i] && strl[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (strl[i] && strl[i] != '\n')
	{
		str[i] = strl[i];
		i++;
	}
	if (strl[i] == '\n')
	{
		str[i] = strl[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*strl;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	strl = rftls(fd, strl);
	if (!strl)
		return (NULL);
	line = get_line(strl);
	strl = renew_left_str(strl);
	return (line);
}
