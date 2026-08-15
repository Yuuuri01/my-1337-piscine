/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamossai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 18:45:58 by hamossai          #+#    #+#             */
/*   Updated: 2026/07/27 00:52:18 by hamossai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
void	ft_putnbr(int nb)
{
	char	c;
	int		i;
	int		i;

	if(nb > 9)
		ft_putnbr(nb  / 10);
	c = (nb % 10) + 48;
	write(1, &c, 1);
}*/
int	is_safe(int *board, int row, int col)
{
	int	i;

	i = 0;
	while (i < row)
	{
		if (board[i] == col)
			return (0);
		if (board[i] - i == col - row)
			return (0);
		if (board[i] + i == col + row)
			return (0);
		i++;
	}
	return (1);
}

void	print_solution(int *board)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = board[i++] + 48;
		write(1, &c, 1);
	}
	write(1, "\n", 1);
}

void	solve_ten_queens_puzzle(int *board, int row, int *sol)
{
	int	col;

	if (row == 10)
	{
		print_solution(board);
		(*sol)++;
		return ;
	}
	col = 0;
	while (col < 10)
	{
		if (is_safe(board, row, col))
		{
			board[row] = col;
			solve_ten_queens_puzzle(board, row + 1, sol);
		}
		col++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	solutions;

	solutions = 0;
	solve_ten_queens_puzzle(board, 0, &solutions);
	return (solutions);
}
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_ten_queens_puzzle());
}
