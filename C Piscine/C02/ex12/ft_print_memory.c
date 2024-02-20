/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaudio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 21:31:26 by fgaudio           #+#    #+#             */
/*   Updated: 2023/09/25 20:59:56 by fgaudio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned long long	pow_nz(int base, int exp)
{
	unsigned long long	ret;
	int					i;

	ret = 1;
	i = 0;
	while (i < exp)
	{
		ret *= base;
		i++;
	}
	return (ret);
}

void	print_hex(unsigned long long addr, int it)
{
	int					div;
	unsigned long long	mod;
	char				hex;

	if (it < 0)
		return ;
	div = addr / pow_nz(16, it);
	mod = addr % pow_nz(16, it);
	if (div <= 9)
		hex = div + 48;
	else
		hex = div + 87;
	write(1, &hex, 1);
	print_hex(mod, it - 1);
}

void	hex_dump(int i, void *addr, unsigned int size)
{
	int	j;
	int	k;

	j = 0;
	while (j < 16)
	{
		k = 0;
		while (k < 2)
		{
			if (addr + i * 16 + j >= addr + size)
				write(1, "   ", 3);
			else
			{
				if (k == 0)
					write(1, " ", 1);
				print_hex(*(i * 16 + (unsigned char *)addr + j), 1);
				if (k == 1)
					write(1, " ", 1);
			}
			j++;
			k++;
		}
	}
}

void	ascii_dump(int i, void *addr, unsigned int size)
{
	int	j;

	j = 0;
	while (j < 16)
	{
		if (addr + i * 16 + j >= addr + size)
			break ;
		else
		{
			if (*(i * 16 + (unsigned char *)addr + j) >= 32)
			{
				if (*(i * 16 + (unsigned char *)addr + j) <= 126)
					write(1, i * 16 + (unsigned char *)addr + j, 1);
				else
					write(1, ".", 1);
			}
			else
				write(1, ".", 1);
		}
		j++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int	i;
	int	lines;

	if (size == 0)
		return (addr);
	i = 0;
	if (size % 16 == 0)
		lines = size / 16;
	else
		lines = size / 16 + 1;
	while (i < lines)
	{
		print_hex((unsigned long long)addr + i * 16, 15);
		write(1, ":", 1);
		hex_dump(i, addr, size);
		ascii_dump(i, addr, size);
		i++;
		write(1, "\n", 1);
	}
	return (addr);
}
