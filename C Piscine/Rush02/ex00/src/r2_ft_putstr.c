/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:23:41 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/08 19:24:08 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/r2_lib.h" 

void	put_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
		write(1, &str[i++], 1);
}
