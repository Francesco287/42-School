/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaudio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:03:41 by fgaudio           #+#    #+#             */
/*   Updated: 2023/09/21 19:56:56 by fgaudio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	pow_nz(int base, int exp)
{
	int	ret;
	int	i;

	ret = 1;
	i = 0;
	while (i < exp)
	{
		ret *= base;
		i++;
	}
	return (ret);
}

void	write_d(int checks, int n, int *digits)
{
	int		i;
	char	c;

	if (checks == n)
	{
		i = 0;
		while (i < n)
		{
			c = digits[i] + 48;
			write(1, &c, 1);
			i++;
		}
		if (digits[0] != 10 - n)
			write(1, ", ", 1);
	}
}

void	checks(int n, int *digits)
{
	int		i;
	int		checks;

	checks = 1;
	i = 1;
	while (i < n)
	{
		if (digits[i] > digits[i - 1])
			checks++;
		else
			break ;
		i++;
	}
	write_d(checks, n, digits);
}

int	set_max_nbr(int n)
{
	int	i;
	int	max_nbr;

	max_nbr = 9;
	i = 2;
	while (i <= n)
	{
		max_nbr = max_nbr * 10 + 9;
		i++;
	}
	return (max_nbr);
}

void	ft_print_combn(int n)
{
	int		max_nbr;
	int		i;
	int		counter;
	int		digits[9];
	int		tmp;

	max_nbr = set_max_nbr(n);
	counter = 0;
	while (counter <= max_nbr)
	{
		tmp = counter;
		i = 0;
		while (i < n)
		{
			digits[i] = tmp / pow_nz(10, n - i - 1);
			tmp %= pow_nz(10, n - i - 1);
			i++;
		}
		checks(n, digits);
		counter++;
	}
}
