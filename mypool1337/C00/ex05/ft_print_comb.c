/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamossai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 18:34:21 by hamossai          #+#    #+#             */
/*   Updated: 2026/07/16 19:23:53 by hamossai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	solve_comb(char *arr, int index, char value)
{
	int	i;

	if (index == 3)
	{
		i = 0;
		while (i < 3)
			write(1, &(arr[i++]), 1);
		if (arr[0] != '7')
			write(1, ", ", 2);
		return ;
	}
	while (value <= '9')
	{
		arr[index] = value;
		solve_comb(arr, index + 1, value + 1);
		value++;
	}
}

void	ft_print_comb(void)
{
	char	tab[3];

	solve_comb(tab, 0, '0');
}
