/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaudio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:51:27 by fgaudio           #+#    #+#             */
/*   Updated: 2023/10/03 18:51:32 by fgaudio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	ret;

	ret = 1;
	if (nb > 0)
	{
		ret *= nb * ft_recursive_factorial(nb - 1);
		return (ret);
	}
	else if (nb == 0)
		return (1);
	else
		return (0);
}
