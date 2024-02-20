#include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len)
{
    size_t i;
    size_t j;

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