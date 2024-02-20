/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaudio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:00:05 by fgaudio           #+#    #+#             */
/*   Updated: 2023/10/05 19:00:06 by fgaudio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	argc--;
	while (argc > 0)
	{
		i = 0;
		while (argv[argc][i])
		{
			write(1, &argv[argc][i], 1);
			i++;
		}
		write(1, "\n", 1);
		argc--;
	}
	return (0);
}
