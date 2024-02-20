/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaudio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:51:53 by fgaudio           #+#    #+#             */
/*   Updated: 2023/10/03 18:51:55 by fgaudio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	ret;

	ret = 1;
	if (power > 0)
	{
		ret *= nb * ft_recursive_power(nb, power - 1);
		return (ret);
	}
	else if (power == 0)
		return (1);
	else
		return (0);
}
