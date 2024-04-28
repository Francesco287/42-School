/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaudio <fgaudio@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 00:39:08 by fgaudio           #+#    #+#             */
/*   Updated: 2024/04/28 18:36:38 by fgaudio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

// #include <fcntl.h>
// #include <time.h>
// int main()
// {
// 	double tot_time = 0;
// 	char *str;
// 	for (int i = 0; i < 10000; i++)
// 	{
// 		int fd = open("test.txt", O_RDONLY);
// 		clock_t begin = clock();
// 		str = get_next_line(fd);
// 		free(str);
// 		clock_t end = clock();
// 		close(fd);
// 		tot_time += (double)(end - begin) / CLOCKS_PER_SEC;
// 	}
// 	printf("Average time: %lf\n", tot_time / 10000);
// }