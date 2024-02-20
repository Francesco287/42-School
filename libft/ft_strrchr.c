char *ft_strrchr(const char *s, int c)
{
    char *tmp; 
    char f;
    char *lastOcc = 0;
    
    tmp = (char *)s;
    f = (unsigned char)c;
    while(*tmp)
    {
        if (*tmp == f)
            lastOcc = tmp;
        tmp++;
    }
    if (*tmp == f)
        lastOcc = tmp;
    return (lastOcc);
}