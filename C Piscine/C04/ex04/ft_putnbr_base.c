/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaudio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 10:56:21 by fgaudio           #+#    #+#             */
/*   Updated: 2023/09/30 11:04:08 by fgaudio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	checks(int *i, char *base)
{
	int	j;

	*i = 0;
	j = 0;
	while (base[*i])
	{
		if (base[*i] == '+' || base[*i] == '-' || base[*i] == '%'
			|| base[*i] == '/' || base[*i] == '*' || base[*i] == '='
			|| base[*i] == ',' || base[*i] == '.'
			|| base[*i] < 33 || base[*i] > 126)
			return (1);
		while (base[j])
		{
			if (base[*i] == base[j] && *i != j)
				return (1);
			j++;
		}
		j = 0;
		(*i)++;
	}
	if (!base[0] || !base[1])
		return (1);
	return (0);
}

void	print_nbr(long n, char *base, int base_len)
{
	if (n < 0)
	{
		write(1, "-", 1);
		print_nbr(-n, base, base_len);
	}
	else if (n <= base_len - 1)
		write(1, &base[n], 1);
	else if (n > base_len - 1)
	{
		print_nbr(n / base_len, base, base_len);
		print_nbr(n % base_len, base, base_len);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

	if (checks(&base_len, base))
		return ;
	print_nbr(nbr, base, base_len);
}
