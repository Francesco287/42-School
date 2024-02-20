/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaudio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:46:31 by fgaudio           #+#    #+#             */
/*   Updated: 2023/09/21 19:56:33 by fgaudio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	int_to_string(int n, char *str)
{
	str[0] = n / 10 + 48;
	str[1] = n % 10 + 48;
}

void	ft_print_comb2(void)
{
	int		i;
	int		j;
	char	str[2];

	i = 0;
	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			int_to_string(i, str);
			write(1, &str, 2);
			write(1, " ", 1);
			int_to_string(j, str);
			write(1, &str, 2);
			if (i == 98)
				break ;
			write(1, ", ", 2);
			j++;
		}
		i++;
	}
}
