#include <stdio.h>
#include "ft_strnstr.c"

int main()
{
    char s1[] = {'c', 'i', 'a', 'o', ' ', 'm', 'o', 'n', 'd', 'o', '!'};
    char *s2 = "ao£$";

    printf("%s\n", ft_strnstr(s1, s2, 2));
}