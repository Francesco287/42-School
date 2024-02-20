#include "libft.h"

char *ft_strchr(const char *s, int c)
{
    char *tmp; 
    char f;
    
    tmp = (char *)s;
    f = (unsigned char)c;
    while(*tmp)
    {
        if (*tmp == f)
            return (tmp);
        tmp++;
    }
    if (*tmp == f)
        return (tmp);
    return (0);
}