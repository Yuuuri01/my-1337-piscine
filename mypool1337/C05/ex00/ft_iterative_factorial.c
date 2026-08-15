/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamossai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 13:26:03 by hamossai          #+#    #+#             */
/*   Updated: 2026/07/25 13:32:44 by hamossai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	res;
	int	i;

	if (nb < 0)
		return (0);
	i = 2;
	res = 1;
	while (i <= nb)
		res *= i++;
	return (res);
}
/*
#include <stdio.h>

int main()
{
	printf("%d\n", ft_iterative_factorial(0));
	
}
*/
