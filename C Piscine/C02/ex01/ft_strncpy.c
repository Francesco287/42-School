/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaudio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:34:33 by fgaudio           #+#    #+#             */
/*   Updated: 2023/09/25 18:03:47 by fgaudio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int				null;
	unsigned int	i;

	null = 0;
	i = 0;
	while (i < n)
	{
		if (src[i] == '\0')
			null++;
		if (null)
			dest[i] = 0;
		else
			dest[i] = src[i];
		i++;
	}
	return (dest);
}
