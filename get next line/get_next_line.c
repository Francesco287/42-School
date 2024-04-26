#include "get_next_line.h"

char	*get_next_line(int fd)
{
	// Suppongo che fd sia riferito a un file.
	// In questo modo non devo preoccuparmi di tenere traccia dell'offset del file.

	char	*buffer;
	char	*tmp;
	int	i;

	buffer = malloc(1);
	if (read(fd, buffer, 1) == 0)
		return NULL;
	i = 0;
	while(buffer[i] != '\n')
	{
		add_one(&buffer, i++);
		if (read(fd, buffer + i, 1) == 0)
			break;
	}
	add_one(&buffer, i++);
	buffer[i] = '\0';
	return (buffer);
}





#include <fcntl.h>

int main()
{
	int fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
