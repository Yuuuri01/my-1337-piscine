/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamossai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 13:54:01 by hamossai          #+#    #+#             */
/*   Updated: 2026/07/22 14:01:27 by hamossai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*str && (*str == 32 || (*str >= 8 && *str <= 13)))
		str++;
	while (*str == 45 || *str == 43)
	{
		if (*str == 45)
			sign = -sign;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		res = (res * 10 + (*str - 48));
		str++;
	}
	return (res * sign);
}
/*
int main()
{
	printf("%d\n", ft_atoi(" ---+--+1234ab567"));
}
*/
