/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamossai <hamossai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 16:56:02 by hamossai          #+#    #+#             */
/*   Updated: 2026/08/15 18:23:08 by hamossai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	ft_is_printable(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

void	ft_putstr(char *str, int std)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(std, str, i);
}
/*
void	ft_print_map(char)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		ft_putstr(map->grid[i], 1);
		write(1, "\n", 1);
		i++;
	}
	ft_free(map, map->rows - 1);
}
*/
