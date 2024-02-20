int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	int				ret;

	if (n == 0)
		return (0);
	ret = 0;
	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			ret = s1[i] - s2[i];
			break ;
		}
		i++;
	}
	if (s1[i] == '\0' || s2[i] == '\0')
		ret = s1[i] - s2[i];
	return (ret);
}
