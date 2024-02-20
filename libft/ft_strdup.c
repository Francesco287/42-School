#include <stdlib.h>

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static void *ft_memcpy(void *dest, const void *src, unsigned int n)
{
    unsigned int i = 0;

    if (!dest && !src)
		return (0);

    while (i < n)
    {
        ((unsigned char *)dest)[i] = ((unsigned char *)src)[i];

        i++;
    }

    return (dest);
}

char *ft_strdup(const char *s)
{
    int slen;
    char *dup;

    slen = ft_strlen(s) + 1;
    dup = (char *)malloc(slen);
    if (!dup)
        return (0);
    ft_memcpy(dup, s, slen);
    return (dup);
}