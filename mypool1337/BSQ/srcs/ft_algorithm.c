/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamossai <hamossai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 18:44:32 by hamossai          #+#    #+#             */
/*   Updated: 2026/08/15 18:22:09 by hamossai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int ft_min(int **map_calc, int i, int j)
{
	int min;
	int b;
	int c;

	min = map_calc[i - 1][j];
	b = map_calc[i][j - 1];
	c = map_calc[i - 1][j - 1];
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return (min);
}

void ft_fill_calc(t_map *map, int **map_calc)
{
	int i;
	int j;

	i = -1;
	while (++i < map->rows)
	{
		j = -1;
		while (++j < map->cols)
		{
			if (map->grid[i][j] == map->obs)
				map_calc[i][j] = 0;
			else if (i == 0 || j == 0)
				map_calc[i][j] = 1;
			else
				map_calc[i][j] = ft_min(map_calc, i, j) + 1;
			if (map_calc[i][j] > map->max_size)
			{
				map->max_size = map_calc[i][j];
				map->max_row = i;
				map->max_col = j;
			}
		}
	}
}

void ft_print_map(t_map *map, int **map_calc)
{
	int i;
	int j;

	i = map->max_row - map->max_size + 1;
	while (map->max_size > 0 && i <= map->max_row)
	{
		j = map->max_col - map->max_size + 1;
		while (j <= map->max_col)
		{
			map->grid[i][j] = map->x;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < map->rows)
	{
		ft_putstr(map->grid[i], 1);
		write(1, "\n", 1);
		free(map_calc[i]);
		i++;
	}
	free(map_calc);
	ft_free(map, map->rows - 1);
}

void ft_find_square(t_map *map)
{
	int **map_calc;

	map_calc = ft_creat_map_calc(map->rows, map->cols);
	if (!map_calc)
	{
		ft_free(map, map->rows - 1);
		return;
	}
	map->max_size = 0;
	map->max_row = 0;
	map->max_col = 0;
	ft_fill_calc(map, map_calc);
	ft_print_map(map, map_calc);
}
