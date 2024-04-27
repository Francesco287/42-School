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
		return 0;
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
		*((int *)s_buf[2]) = (int)read(fd, (char *)s_buf[0], BUFFER_SIZE);
		if (*((int *)s_buf[2]) == 0)
			return (0);
		s_buf[1] = s_buf[0];
	}
	if (s_buf[1] - s_buf[0] == *((int *)s_buf[2]))
		return (0);
	if (add_one(buffer, i) || *((int *)s_buf[2]) == -1)
		return (-1);
	(*buffer)[i] = *((char *)s_buf[1]);
	s_buf[1]++;
	return (1);
}

// int	get_next_char(int fd, char **buffer, int i)
// {
// 	static char	*s_buf[2];
// 	static int	char_read;

// 	if (s_buf[0] == NULL)
// 	{
// 		s_buf[0] = malloc(BUFFER_SIZE);
// 		s_buf[1] = s_buf[0] + BUFFER_SIZE;
// 	}
// 	if (s_buf[1] - s_buf[0] == BUFFER_SIZE)
// 	{
// 		char_read = read(fd, s_buf[0], BUFFER_SIZE);
// 		if (char_read == 0)
// 			return (0);
// 		s_buf[1] = s_buf[0];
// 	}
// 	if (s_buf[1] - s_buf[0] == char_read)
// 		return (0);
// 	add_one(buffer, i);
// 	(*buffer)[i] = *(s_buf[1]);
// 	s_buf[1]++;
// 	return (1);
// }