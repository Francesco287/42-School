/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaudio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:51:34 by fgaudio           #+#    #+#             */
/*   Updated: 2023/09/21 19:56:48 by fgaudio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);

void	big(int nb)
{
	write(1, "2", 1);
	ft_putnbr(nb % 1000000000);
}

void	very_small(void)
{
	write(1, "-2", 2);
	ft_putnbr(147483648);
}

void	interm(int tmp, int *tmp3, int nb)
{
	while (1)
	{
		if (*tmp3 / tmp != 0 || nb / 10 == 0)
			break ;
		write(1, "0", 1);
		*tmp3 *= 10;
	}
}

void	positive(int tmp, int *tmp2, int *tmp3, int nb)
{
	while (1)
	{
		*tmp2 = nb / tmp + 48;
		if (*tmp2 - 48 <= 9)
		{
			write(1, tmp2, 1);
			if (nb % tmp == 0)
			{
				while (nb > 9)
				{
					write(1, "0", 1);
					nb /= 10;
				}
				break ;
			}
			*tmp3 = (nb % tmp) * 10;
			interm(tmp, tmp3, nb);
			if (nb % tmp != 0)
				ft_putnbr(nb % tmp);
			break ;
		}
		else
			tmp *= 10;
	}
}

void	ft_putnbr(int nb)
{
	int	tmp;
	int	tmp2;
	int	tmp3;

	if (nb >= 2147483600)
		big(nb);
	else if (nb > 0)
	{
		tmp = 1;
		positive(tmp, &tmp2, &tmp3, nb);
	}
	else if (nb == -2147483648)
		very_small();
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-nb);
	}
	else
		write(1, "0", 1);
}
