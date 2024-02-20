void *ft_memcpy(void *dest, const void *src, unsigned int n)
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