/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamossai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 23:23:01 by hamossai          #+#    #+#             */
/*   Updated: 2026/07/25 23:28:56 by hamossai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;
	int	length;

	if (max <= min)
		return (NULL);
	length = max - min;
	tab = malloc(length * sizeof(int));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < length)
	{
		tab[i++] = min;
		min++;
	}
	return (tab);
}
/*
#include <stdio.h>

int	main(void)
{
	int min = 0;
	int max = 10;

	int *res = ft_range(min, max);
	int i = 0;
	while(i < 10)
		printf("%d ", res[i++]);
}*/
