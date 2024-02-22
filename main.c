#include <stdio.h>
#include "libft/libft.h"

int main()
{
	char *s = "ciao mondo";
	printf("%s\n", ft_split(s, 'z')[1]);
}