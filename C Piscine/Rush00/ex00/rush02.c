/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaudio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 21:12:31 by fgaudio           #+#    #+#             */
/*   Updated: 2023/09/24 21:12:38 by fgaudio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	i;
	int	j;

	j = 1;
	while (j <= y)
	{
		i = 1;
		while (i <= x)
		{
			if ((i == 1 || i == x) && j == 1)
				ft_putchar('A');
			else if ((i == 1 || i == x) && j == y)
				ft_putchar('C');
			else if (i > 1 && i < x && j > 1 && j < y)
				ft_putchar(' ');
			else
				ft_putchar('B');
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}
