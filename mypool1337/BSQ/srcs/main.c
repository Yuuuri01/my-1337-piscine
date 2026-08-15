/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamossai <hamossai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:04:35 by hamossai          #+#    #+#             */
/*   Updated: 2026/08/15 18:23:19 by hamossai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void ft_full_data_map(t_map *map, char *data, int len_first)
{
	map->empty = data[len_first - 3];
	map->obs = data[len_first - 2];
	map->x = data[len_first - 1];
	map->rows = ft_get_rows(data, len_first - 3);
}

void ft_solve_help(int fd)
{
	t_map map;
	char data[1000];
	char *second_row;
	int len_first;

	len_first = read_first_line(fd, data, 1000);
	if (len_first < 4)
	{
		ft_putstr("map error\n", 1);
		return;
	}
	ft_full_data_map(&map, data, len_first);
	second_row = ft_get_cols_and_save_row(fd, &map.cols);
	if (!second_row || map.cols == 0 || map.rows == -1 || !ft_is_valid(map))
	{
		free(second_row);
		ft_putstr("map error\n", 1);
		return;
	}
	if (!ft_creat_map(fd, &map, second_row))
	{
		ft_putstr("map error\n", 1);
		return;
	}
	ft_find_square(&map);
}

int main(int ac, char **av)
{
	int fd;
	int i;

	if (ac >= 2)
	{
		i = 1;
		while (i < ac)
		{
			fd = open(av[i], O_RDONLY);
			if (fd >= 0)
			{
				ft_solve_help(fd);
				close(fd);
			}
			else
				ft_putstr("map error\n", 1);
			if (i < ac - 1)
				write(1, "\n", 1);
			i++;
		}
	}
	else
		ft_solve_help(0);
	return (0);
}
