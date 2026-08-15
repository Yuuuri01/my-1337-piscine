/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamossai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 18:49:08 by hamossai          #+#    #+#             */
/*   Updated: 2026/07/16 19:23:07 by hamossai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_solution(int *arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
		ft_putchar(arr[i++] + 48);
}

void	solve_combn(int *arr, int index, int RCX, int n)
{
	if (index == n)
	{
		print_solution(arr, n);
		if (arr[0] != 10 - n)
			write(1, ", ", 2);
		return ;
	}
	while (RCX <= 9)
	{
		arr[index] = RCX;
		solve_combn(arr, index + 1, RCX + 1, n);
		RCX++;
	}
}

void	ft_print_combn(int n)
{
	int	arr[10];

	if (n > 0 && n < 10)
		solve_combn(arr, 0, 0, n);
}
