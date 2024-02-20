/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaudio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:50:41 by fgaudio           #+#    #+#             */
/*   Updated: 2023/09/25 18:21:22 by fgaudio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	first_letter;
	int	i;
	int	cond1;
	int	cond2;

	first_letter = 1;
	i = 0;
	while (str[i] != '\0')
	{
		cond1 = str[i] >= 97 && str[i] <= 122;
		cond2 = str[i] >= 65 && str[i] <= 90;
		if ((str[i] >= 48 && str[i] <= 57) || cond1 || cond2)
		{
			if (first_letter && str[i] >= 97 && str[i] <= 122)
				str[i] -= 32;
			else if (!first_letter && str[i] >= 65 && str[i] <= 90)
				str[i] += 32;
			first_letter = 0;
		}
		else
			first_letter = 1;
		i++;
	}
	return (str);
}
