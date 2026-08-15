/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamossai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 15:27:40 by hamossai          #+#    #+#             */
/*   Updated: 2026/07/25 16:01:27 by hamossai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (nb == 1)
		return (nb);
	return (nb * ft_recursive_power(nb, power - 1));
}
/*
#include <stdio.h>
int main()
{
    // 1. Standard Positive Powers
    printf("%d (Expected: 32)\n", ft_recursive_power(2, 5));
    printf("%d (Expected: 64)\n", ft_recursive_power(4, 3));
    printf("%d (Expected: 100)\n", ft_recursive_power(10, 2));

    // 2. Exponent Zero (Identity)
    printf("%d (Expected: 1)\n", ft_recursive_power(2, 0));
    printf("%d (Expected: 1)\n", ft_recursive_power(500, 0));
    printf("%d (Expected: 1)\n", ft_recursive_power(-10, 0));

    // 3. Exponent One (Critical for your logic fix)
    printf("%d (Expected: 2)\n", ft_recursive_power(2, 1));
    printf("%d (Expected: 0)\n", ft_recursive_power(0, 1));
    printf("%d (Expected: -5)\n", ft_recursive_power(-5, 1));

    // 4. Negative Exponents (Should return 0 for int return type)
    printf("%d (Expected: 0)\n", ft_recursive_power(2, -1));
    printf("%d (Expected: 0)\n", ft_recursive_power(5, -10));

    // 5. Zero Base
    printf("%d (Expected: 0)\n", ft_recursive_power(0, 5));
    printf("%d (Expected: 1)\n", ft_recursive_power(0, 0));

    // 6. Negative Base (Sign handling)
    printf("%d (Expected: -8)\n", ft_recursive_power(-2, 3));
    printf("%d (Expected: 16)\n", ft_recursive_power(-2, 4));

    return (0);
}
*/
