/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamossai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 20:39:23 by hamossai          #+#    #+#             */
/*   Updated: 2026/07/25 15:10:31 by hamossai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	valid_base(char *base, int *len)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] <= 32 || base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	*len = i;
	return (1);
}

int	get_position(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

void	skipi(char *str, int *sign, int *index)
{
	while ((str[*index] == 32 || (str[*index] >= 9 && str[*index] <= 13)))
	{
		if (!str[*index])
			break ;
		(*index)++;
	}
	*sign = 1;
	while (str[*index] == '+' || str[*index] == '-')
	{
		if (str[*index] == '-')
			*sign *= -1;
		(*index)++;
	}
}

int	ft_atoi_base(char *str, char *base)
{
	int	index;
	int	sign;
	int	len;
	int	pos;
	int	res;

	len = 0;
	if (!valid_base(base, &len))
		return (0);
	index = 0;
	sign = 1;
	skipi(str, &sign, &index);
	res = 0;
	while (str[index])
	{
		pos = get_position(str[index], base);
		if (pos != -1)
			res = res * len + pos;
		else
			return (res * sign);
		index++;
	}
	return (res * sign);
}
/*
#include <stdio.h>
int main()
{
	int res = ft_atoi_base("2147483647", "0123456789");
	printf("%d\n", res);
	printf("%d\n", ft_atoi_base("1op", "0123456789abcdefghijklmnop"));
	printf("%d\n", ft_atoi_base("1010", "01"));
	printf("%d\n", ft_atoi_base("17", "01234567"));
}*/
