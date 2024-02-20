/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:24:20 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/08 19:24:27 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			ret += (unsigned char)s1[i] - (unsigned char)s2[i];
			break ;
		}
		i++;
	}
	if (s1[i] == '\0')
		ret += (unsigned char)s1[i] - (unsigned char)s2[i];
	return (ret);
}
