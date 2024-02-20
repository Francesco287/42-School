/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaudio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:15:57 by fgaudio           #+#    #+#             */
/*   Updated: 2023/10/03 18:42:06 by fgaudio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	checks(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == '%'
			|| base[i] == '/' || base[i] == '*' || base[i] == '='
			|| base[i] == ',' || base[i] == '.'
			|| base[i] < 33 || base[i] > 126)
			return (1);
		while (base[j])
		{
			if (base[i] == base[j] && i != j)
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	if (!base[0] || !base[1])
		return (1);
	return (0);
}

int	in_b(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}

int	power(char *base, int exp)
{
	int	b;
	int	ret;

	b = 0;
	while (base[b])
		b++;
	ret = 1;
	while (exp > 0)
	{
		ret *= b;
		exp--;
	}
	return (ret);
}

void	aux_cycle(char *str, char buffer[100], int *sign, char *base)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
	{
		i++;
	}
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	while (in_b(str[i], base))
	{
		buffer[j] = str[i];
		buffer[j + 1] = '\0';
		i++;
		j++;
	}
}

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		sign;
	char	buffer[100];
	int		buffer_len;
	int		ret;

	if (checks(base))
		return (0);
	sign = 1;
	aux_cycle(str, buffer, &sign, base);
	buffer_len = 0;
	while (buffer[buffer_len])
		buffer_len++;
	ret = 0;
	i = 0;
	while (i < buffer_len)
	{
		ret += (in_b(buffer[i], base) - 1) * power(base, buffer_len - 1 - i);
		i++;
	}
	return (ret * sign);
}
