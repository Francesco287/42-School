/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaudio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:53:43 by fgaudio           #+#    #+#             */
/*   Updated: 2023/09/27 23:15:40 by fgaudio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	j;

	if (to_find[0] == '\0')
		return (str);
	j = 0;
	while (*str != '\0')
	{
		if (*str == to_find[j])
		{
			while (to_find[j] != '\0' && str[j] == to_find[j] && str[j])
			{
				j++;
				if (to_find[j] == '\0')
					return (str);
			}
		}
		str++;
	}
	return (0);
}
