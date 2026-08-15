/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamossai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 23:30:15 by hamossai          #+#    #+#             */
/*   Updated: 2026/07/27 00:21:49 by hamossai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	length;
	int	*tab;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	length = max - min;
	tab = malloc(length * sizeof(int));
	if (!tab)
		return (-1);
	i = 0;
	while (i < length)
		tab[i++] = min++;
	*range = tab;
	return (length);
}
// #include <stdio.h>
// int main()
// {
//     int min = 1;
//     int max = 10;
//     int *range = NULL;

//     int len = ft_ultimate_range(&range, min, max);
//     int i = 0;

//     if(!range)
//     {
//         printf("KO %d\n", len);
//         i = len;
//     }
//     while(i < len)
//         printf("%d ", range[i++]);
//     free(range);
// }
