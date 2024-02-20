#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
    void *ptr;
    size_t i = 0;

    if (!nmemb || !size)
        return (0);
    ptr = malloc(nmemb * size);
    while (i < nmemb * size)
    {
        ((unsigned char *)ptr)[i] = 0;
        i++;
    }
    return (ptr);
}