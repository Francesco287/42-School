void *ft_memchr(const void *s, int c, unsigned int n)
{
    unsigned char f;
    int i;
    
    f = (unsigned char)c;
    i = 0;
    while (i < n)
    {
        if (((unsigned char *)s)[i] == f)
            return ((void *)s + i);
        i++;
    }
    return (0);
}