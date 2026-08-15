/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamossai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 15:09:00 by hamossai          #+#    #+#             */
/*   Updated: 2026/07/20 21:19:35 by hamossai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(unsigned char c)
{
	char	*base;

	base = "0123456789abcdef";
	write(1, &base[c / 16], 1);
	write(1, &base[c % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	while (*ptr)
	{
		if (!(*ptr >= 32 && *ptr <= 126))
		{
			write(1, "\\", 1);
			print_hex(*ptr);
		}
		else
			write(1, &(*ptr), 1);
		ptr++;
	}
}
/*
int main()
{
	char c = (char)0xFF;
	print_hex(c);
//	char *str = "Hello\nhow are you?";
//	char *str2 = "Hello\rHow are you?";
//	ft_putstr_non_printable(str);
//	write(1, "\n", 1);
//	ft_putstr_non_printable(str2);
}
*/
