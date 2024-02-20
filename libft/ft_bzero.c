void ft_bzero(void *s, unsigned int n)
{
    unsigned int i = 0;

    while (i < n)
    {
        ((unsigned char *)s)[i] = '\0';

        i++;
    }

    return s;
}