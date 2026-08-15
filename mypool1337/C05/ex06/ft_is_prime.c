/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamossai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 17:58:31 by hamossai          #+#    #+#             */
/*   Updated: 2026/07/25 18:03:51 by hamossai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	i = 2;
	while (i * i <= nb)
	{
		if (!(nb % i))
			return (0);
		i++;
	}
	return (1);
}
/*
#include <stdio.h>
int main()
{
	int i = 0;
	while(i <= 10)
	{
		printf("%d\n", ft_is_prime(i++));
	}
}*/
