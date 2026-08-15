/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamossai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 16:26:48 by hamossai          #+#    #+#             */
/*   Updated: 2026/07/21 14:48:07 by hamossai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(unsigned char nb)
{
	char	*base;

	base = "0123456789abcdef";
	write(1, &(base[nb / 16]), 1);
	write(1, &(base[nb % 16]), 1);
}

void	print_address_ptr(unsigned long ptr, int size)
{
	int		n;
	char	*base;

	base = "0123456789abcdef";
	if (size < 0)
	{
		write(1, ": ", 2);
		return ;
	}
	n = (ptr >> (size * 4)) & 15;
	write(1, &(base[n]), 1);
	print_address_ptr(ptr, size - 1);
}

void	print_line(unsigned char *ptr, unsigned int index, unsigned int size)
{
	unsigned char	i;

	i = 0;
	while (i < 16)
	{
		if (i + index < size)
			print_hex(ptr[i + index]);
		else
			write(1, "  ", 2);
		if (i % 2 != 0)
			write(1, " ", 1);
		i++;
	}
}

void	print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned long	add;
	unsigned char	*ptr;

	ptr = (unsigned char *)addr;
	add = (unsigned long)ptr;
	i = 0;
	while (i < size)
	{
		print_address_ptr(add + i, 15);
		j = 0;
		print_line(ptr, i, size);
		while (j < 16 && i + j < size)
		{
			if (ptr[i + j] >= 32 && ptr[i + j] <= 126)
				write(1, &(ptr[i + j]), 1);
			else
				write(1, ".", 1);
			j++;
		}
		write(1, "\n", 1);
		i += 16;
	}
	return ((void)addr);
}
/*
int main()
{
	char str[] = "Bonjour les aminches...c. e\tst fou.tout.ce"; 
        unsigned int size = sizeof(str) - 1;
        print_memory(str, size);
 
       	//unsigned long ptr = (unsigned long)str;
        //print_address_ptr(ptr, 15);
}
*/
