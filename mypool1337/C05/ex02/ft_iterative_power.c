/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamossai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 13:37:29 by hamossai          #+#    #+#             */
/*   Updated: 2026/07/25 15:26:56 by hamossai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	res;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	res = nb;
	while (power > 1)
	{
		res *= nb;
		power--;
	}
	return (res);
}
/*
#include <stdio.h>
int main()
{
	printf("%d\n", ft_iterative_power(2, 1));
	printf("%d\n", ft_iterative_power(4, 3));
	printf("%d\n", ft_iterative_power(10, 2));
	printf("%d\n", ft_iterative_power(2, 0));
	printf("%d\n", ft_iterative_power(500, 0));
	printf("%d\n", ft_iterative_power(-10, 0));
	printf("%d\n", ft_iterative_power(0, 1));
}
*/
