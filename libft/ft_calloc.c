/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaudio <fgaudio@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:27:23 by fgaudio           #+#    #+#             */
/*   Updated: 2024/02/21 21:27:23 by fgaudio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	if (!nmemb || !size)
		return (0);
	ptr = malloc(nmemb * size);
	while (i < nmemb * size)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
