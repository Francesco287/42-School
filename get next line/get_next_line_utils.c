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

void	add_one(char **str, int i)
{
	char	*tmp;

	if (i == 0)
	{
		*str = malloc(1);
		return ;
	}
	tmp = malloc(i + 1);
	str_cpy(tmp, *str, i + 1);
	free(*str);
	*str = malloc(++i + 1);
	str_cpy(*str, tmp, i + 1);
	free(tmp);
}

int	get_next_char(int fd, char **buffer, int i)
{
	static char	*s_buf[2];

	if (s_buf[0] == NULL)
	{
		s_buf[0] = malloc(BUFFER_SIZE);
		s_buf[1] = s_buf[0] + BUFFER_SIZE;
	}
	if (s_buf[1] - s_buf[0] == BUFFER_SIZE)
	{
		if (read(fd, s_buf[0], BUFFER_SIZE) == 0)
			return (0);
		s_buf[1] = s_buf[0];
	}
	add_one(buffer, i);
	(*buffer)[i] = *(s_buf[1]);
	s_buf[1]++;
	return (1);
}
