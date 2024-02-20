char *ft_strnstr(const char *big, const char *little, unsigned int len)
{
    unsigned int i;
    unsigned int j;

    i = 0;
    j = 0;
    if (little[0] == '\0')
        return ((char *)big);
    while(big[i])
    {
        while(little[j])
        {
            if (little[j] == big[i + j])
            {
                if (little[j + 1] == '\0' || j == len - 1)
                    return ((char *)big + i);
            }
            else
                break;
            j++;
        }
        i++;
    }
    return (0);
}