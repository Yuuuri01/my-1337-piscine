/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saboutay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 16:07:53 by saboutay          #+#    #+#             */
/*   Updated: 2026/08/05 16:18:16 by saboutay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	char	**grid;
	char	empty;
	char	obs;
	char	x;
	int		rows;
	int		cols;
	int		max_size;
	int		max_row;
	int		max_col;
}			t_map;
int			read_first_line(int fd, char *data, int size);
int			ft_get_rows(char *str, int end);
int			ft_is_valid(t_map map);
int			ft_creat_map(int fd, t_map *map, char *second_row);
int			ft_is_printable(char c);
int			**ft_creat_map_calc(int rows, int cols);
char		*ft_get_cols_and_save_row(int fd, int *cols);
char		*ft_add_size(char *row, int old_size, int new_size);
void		ft_putstr(char *str, int std);
void		ft_find_square(t_map *map);
void		ft_free(t_map *map, int i);

#endif
