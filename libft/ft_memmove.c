#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
    size_t i = 0;
    unsigned char tmp[n];

	if (!dest && !src)
		return (0);

    while (i < n)
    {
        tmp[i] = ((unsigned char *)src)[i];

        i++;
    }

    while (i < 2 * n)
    {
        ((unsigned char *)dest)[i - n] = tmp[i - n];

        i++;
    }

    return (dest);
}