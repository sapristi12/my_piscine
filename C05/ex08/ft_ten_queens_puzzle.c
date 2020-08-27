/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 14:44:43 by erlajoua          #+#    #+#             */
/*   Updated: 2020/08/11 13:08:42 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	fill_board(int board[10][10])
{
	int i;
	int j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	show_tab(int tab[10][10])
{
	int		i;
	int		j;
	char	to_show;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			to_show = j + '0';
			if (tab[i][j] == 1)
				write(1, &to_show, 1);
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
}

int		check_left(int board[10][10], int row, int col)
{
	int to_c;
	int to_r;

	to_c = -1;
	while (to_c++ < col)
		if (board[to_c][row] == 1)
			return (0);
	to_r = row + 1;
	to_c = col + 1;
	while (to_r-- > 0 && to_c-- > 0)
		if (board[to_c][to_r] == 1)
			return (0);
	to_r = row - 1;
	to_c = col + 1;
	while (to_c-- > 0 && to_r++ < 9)
		if (board[to_c][to_r] == 1)
			return (0);
	return (1);
}

int		solve(int board[10][10], int col, int *solved)
{
	int row;

	row = 0;
	if (col >= 10)
		return (1);
	while (row < 10)
	{
		if (check_left(board, row, col))
		{
			board[col][row] = 1;
			if (solve(board, col + 1, solved))
			{
				show_tab(board);
				*solved = *solved + 1;
			}
			board[col][row] = 0;
		}
		row++;
	}
	return (0);
}

int		ft_ten_queens_puzzle(void)
{
	int board[10][10];
	int solved;

	fill_board(board);
	solve(board, 0, &solved);
	return (solved);
}
