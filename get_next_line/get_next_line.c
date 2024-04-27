#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	int		i;
	int		err_check;

	if (fd < 0)
		return (NULL);
	i = 0;
	err_check = get_next_char(fd, &buffer, i);
	while (err_check)
	{
		if (err_check == -1)
			return (NULL);
		if (buffer[i++] == '\n')
			break;
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
// 	int fd = open("./gnlTester/files/big_line_with_nl", O_RDONLY);
// 	char *str;
// 	for (int i = 0; i < 7; i++)
// 	{
// 		str = get_next_line(fd);
// 		printf("%s", str);
// 		printf("\n-----------------\n");
// 		free(str);
// 	}
// }