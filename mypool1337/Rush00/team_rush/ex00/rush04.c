/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saboutay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 15:26:45 by saboutay          #+#    #+#             */
/*   Updated: 2026/07/19 13:33:25 by saboutay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_x(int x, char start, char mid, char end)
{
	int	i;

	i = 1;
	while (i <= x)
	{
		if (i == 1)
			ft_putchar(start);
		else if (i != 1 && i != x)
			ft_putchar(mid);
		else if (i == x)
			ft_putchar(end);
		i++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	if (x < 0 || y < 0)
		return ;
	i = 1;
	while (i <= y)
	{
		if (i == 1)
			ft_print_x(x, 'A', 'B', 'C');
		else if (i != 1 && i != y)
			ft_print_x(x, 'B', ' ', 'B');
		else if (i == y)
			ft_print_x(x, 'C', 'B', 'A');
		i++;
	}
}
