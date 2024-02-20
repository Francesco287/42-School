#include <stdlib.h>

void *ft_calloc(unsigned int nmemb, unsigned int size)
{
    void *ptr;
    unsigned int i = 0;

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