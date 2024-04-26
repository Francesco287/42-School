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

	tmp = malloc(i + 1);
	str_cpy(tmp, *str, i + 1);
	free(*str);
	*str = malloc(++i + 1);
	str_cpy(*str, tmp, i + 1);
	free(tmp);
}
