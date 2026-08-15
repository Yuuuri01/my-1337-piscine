/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory_alloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamossai <hamossai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 15:33:22 by hamossai          #+#    #+#             */
/*   Updated: 2026/08/15 18:22:28 by hamossai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	ft_free(t_map *map, int i)
{
	while (i >= 0)
	{
		free(map->grid[i]);
		i--;
	}
	free(map->grid);
}

int	ft_fill_map(int fd, t_map *map, int i)
{
	int		bytes;
	int		j;
	char	c;

	map->grid[i] = malloc((map->cols + 1) * sizeof(char));
	if (!map->grid[i])
		return (0);
	j = -1;
	while (++j < map->cols)
	{
		if (read(fd, &c, 1) <= 0 || (c != map->empty && c != map->obs))
		{
			free(map->grid[i]);
			return (0);
		}
		map->grid[i][j] = c;
	}
	map->grid[i][j] = '\0';
	bytes = read(fd, &c, 1);
	if ((bytes == 0 && i == map->rows - 1) || (bytes == 1 && c == '\n'))
		return (1);
	free(map->grid[i]);
	return (0);
}

int	ft_creat_map(int fd, t_map *map, char *second_row)
{
	int		i;
	char	c;

	map->grid = malloc((map->rows) * sizeof(char *));
	if (!map->grid)
	{
		free(second_row);
		return (0);
	}
	map->grid[0] = second_row;
	i = 0;
	while (++i < map->rows)
	{
		if (!ft_fill_map(fd, map, i))
		{
			ft_free(map, i - 1);
			return (0);
		}
	}
	if (read(fd, &c, 1) > 0)
	{
		ft_free(map, map->rows - 1);
		return (0);
	}
	return (1);
}

char	*ft_add_size(char *row, int old_size, int new_size)
{
	char	*new_row;
	int		i;

	new_row = malloc(new_size * sizeof(char));
	if (!new_row)
	{
		free(row);
		return (NULL);
	}
	i = -1;
	while (++i < old_size)
		new_row[i] = row[i];
	free(row);
	return (new_row);
}

int	**ft_creat_map_calc(int rows, int cols)
{
	int	**map;
	int	i;

	map = malloc((rows) * sizeof(int *));
	if (!map)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		map[i] = malloc((cols) * sizeof(int));
		if (!map[i])
		{
			while (--i >= 0)
				free(map[i]);
			free(map);
			return (NULL);
		}
		i++;
	}
	return (map);
}
