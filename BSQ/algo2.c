/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 20:49:04 by erlajoua          #+#    #+#             */
/*   Updated: 2020/08/27 12:38:45 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	fill_map(int **tab, t_variables *vars)
{
	int		i;
	int		j;
	char	**grid;

	grid = init_grid(vars);
	i = -1;
	while (++i < vars->lines)
	{
		j = 0;
		while (j < vars->width)
		{
			if (tab[i][j] == vars->max)
			{
				biggest_square(grid, vars, i, j);
				vars->max = -1;
			}
			else if (tab[i][j] == 0)
				grid[i][j] = vars->obstacle;
			else
				grid[i][j] = vars->empty;
			j++;
		}
	}
	aff_tab(grid, vars);
	free_char_tab(grid, vars);
}

void	aff_tab(char **tab, t_variables *vars)
{
	int i;
	int j;

	i = 0;
	while (i < vars->lines)
	{
		j = 0;
		while (j < vars->width)
		{
			write(1, &tab[i][j], 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}
