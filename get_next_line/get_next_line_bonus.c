/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaudio <fgaudio@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 00:39:08 by fgaudio           #+#    #+#             */
/*   Updated: 2024/04/28 15:14:41 by fgaudio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	buffer[i] = '\0';
	return (buffer);
}

// #include <fcntl.h>

// int main()
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	int fd2 = open("test2.txt", O_RDONLY);
// 	char *str;
// 	for (int i = 0; i < 10; i++)
// 	{
// 		str = get_next_line(fd);
// 		printf("%s", str);
// 		printf("\n-----------------\n");
// 		free(str);
// 		str = get_next_line(fd2);
// 		printf("%s", str);
// 		printf("\n-----------------\n");
// 		free(str);
// 	}
// }