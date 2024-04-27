#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

char	*get_next_line(int fd);
int		add_one(char **str, int i);
int		get_next_char(int fd, char **buffer, int i);

#endif
