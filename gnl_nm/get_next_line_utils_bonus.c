/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaudio <fgaudio@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 22:37:34 by fgaudio           #+#    #+#             */
/*   Updated: 2024/06/23 17:15:42 by fgaudio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *strl, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!strl)
	{
		strl = (char *)malloc(1 * sizeof(char));
		strl[0] = '\0';
	}
	if (!strl || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(strl) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (strl)
		while (strl[++i] != '\0')
			str[i] = strl[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(strl) + ft_strlen(buff)] = '\0';
	free(strl);
	return (str);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*renew_left_str(char *strl)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (strl[i] && strl[i] != '\n')
		i++;
	if (!strl[i])
	{
		free(strl);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(strl) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (strl[i])
		str[j++] = strl[i++];
	str[j] = '\0';
	free(strl);
	return (str);
}

char	*rftls(int fd, char *strl)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(strl, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		strl = ft_strjoin(strl, buff);
	}
	free(buff);
	return (strl);
}
