#include <stdio.h>
#include "libft/libft.h"

int main()
{
	char *s = " woo ow woo ow woo ow ";
	char **splatter = ft_split(s, ' ');
	while (*splatter)
		printf("%s\n", *splatter++);
}