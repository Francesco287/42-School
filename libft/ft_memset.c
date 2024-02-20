void *ft_memset(void *s, int c, unsigned int n)
{
    unsigned int i = 0;

    while (i < n)
    {
        ((unsigned char *)s)[i] = (unsigned char)c;

        i++;
    }

    return s;
}