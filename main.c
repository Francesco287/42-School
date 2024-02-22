#include <stdio.h>
#include "libft/libft.h"

int main()
{
	char *s1 = " ciao mondo   ";
	printf("%s\n", ft_strtrim(s1, " ciao"));
}