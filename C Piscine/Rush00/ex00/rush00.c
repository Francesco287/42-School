/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaudio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 21:06:48 by fgaudio           #+#    #+#             */
/*   Updated: 2023/09/24 21:10:28 by fgaudio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	while_s(int x, int y, int a, int b)
{
	while (x > a)
	{
		if ((a == 0 && b == 0) || (a == x - 1 && b == y - 1))
		{
			ft_putchar('o');
		}
		else if ((a == 0 && b == x - 1) || (a == x - 1 && b == 0))
		{
			ft_putchar('o');
		}
		else if ((a == 0 || a == x - 1) && (b > 0 || b < y - 1))
		{
			ft_putchar('|');
		}
		else if ((a == 0 || b == 0) || (a == x - 1 || b == y - 1))
		{
			ft_putchar('-');
		}
		else
		{
			ft_putchar(' ');
		}
		a++;
	}
}

void	rush(int x, int y)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (y > b)
	{
		a = 0;
		while_s(x, y, a, b);
		b++;
		ft_putchar('\n');
	}
}
