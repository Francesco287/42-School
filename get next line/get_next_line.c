#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	int	i;

	i = 0;
	while (get_next_char(fd, &buffer, i))
		if (buffer[i++] == '\n')
			break;
	if (i == 0)
		return (NULL);
	add_one(&buffer, i - 1);
	buffer[i] = '\0';
	return (buffer);
}










#include <fcntl.h>

int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *str;
	for (int i = 0; i < 13; i++)
	{
		str = get_next_line(fd);
		printf("%s", str);
		printf("\n-----------------\n");
		free(str);
	}
}
