/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamossai <hamossai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 16:40:20 by hamossai          #+#    #+#             */
/*   Updated: 2026/08/15 18:22:46 by hamossai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	read_first_line(int fd, char *data, int size)
{
	int		bytes;
	int		i;
	char	c;

	i = 0;
	bytes = read(fd, &c, 1);
	while (bytes > 0 && c != '\n')
	{
		if (i < size - 1)
		{
			data[i] = c;
			i++;
		}
		bytes = read(fd, &c, 1);
	}
	data[i] = '\0';
	return (i);
}

int	ft_get_rows(char *str, int end)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i < end)
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res);
}

char	*ft_get_cols_and_save_row(int fd, int *cols)
{
	char	*row;
	char	c;
	int		size;

	*cols = 0;
	row = NULL;
	size = 1000;
	row = malloc(size * sizeof(char));
	if (!row)
		return (NULL);
	while (read(fd, &c, 1) > 0 && c != '\n')
	{
		if (*cols >= size - 1)
		{
			row = ft_add_size(row, size, size * 2);
			if (!row)
				return (NULL);
			size *= 2;
		}
		row[*cols] = c;
		(*cols)++;
	}
	row[*cols] = '\0';
	return (row);
}

int	ft_is_valid(t_map map)
{
	if (!ft_is_printable(map.obs) || !ft_is_printable(map.empty)
		|| !ft_is_printable(map.x))
		return (0);
	if (map.cols <= 0 || map.rows <= 0)
		return (0);
	if (map.empty == map.obs || map.empty == map.x || map.x == map.obs)
		return (0);
	return (1);
}
