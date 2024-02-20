/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r2_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:41:30 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/08 22:31:14 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/r2_lib.h"

int	check_negative(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (1);
	while (str[++i])
	{
		if (str[i] == '-')
			return (1);
		else if (str[i] >= '9' && str[i] <= '0')
			return (0);
	}
	return (0);
}

int	count_plus_minus(char *str)
{
	int	i;
	int	special_count;
	int	counting;

	special_count = 0;
	i = -1;
	counting = 0;
	while (str[++i])
	{
		if (str[i] == '-' || str[i] == '+')
			special_count++;
		else if (str[i] >= '0' && str[i] <= '9')
			break ;
		else if (str[i] != ' ')
			return (-1);
	}
	if (special_count > 1)
		return (-1);
	return (0);
}

int	check_error(char *str)
{
	int	i;
	int	counting;

	i = -1;
	counting = 0;
	if (!str)
		return (-3);
	if (count_plus_minus(str))
		return (-1);
	if (check_negative(str))
		return (-2);
	return (0);
}

void	init_parse_values(int *i, int *j, int *counting, char **buff)
{
	*i = -1;
	*j = 0;
	*counting = 0;
	*buff = malloc(128);
}

char	*parse_input(char *str)
{
	char	*buff;
	int		i;
	int		j;
	int		counting;

	init_parse_values(&i, &j, &counting, &buff);
	if (check_error(str))
		return (check_error(str));
	while (str[++i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			counting++;
			buff[j++] = str[i];
		}
		else if (counting)
			break ;
	}
	if (i == 0)
		buff[i++] = '0';
	buff[i] = '\0';
	return (buff);
}
