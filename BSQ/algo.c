/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 20:30:05 by erlajoua          #+#    #+#             */
/*   Updated: 2020/08/27 10:26:15 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		minimum(int a, int b, int c)
{
	int min;

	min = 0;
	if (a <= b)
		min = a;
	else
		min = b;
	if (c <= min)
		min = c;
	return (min);
}

int		**copy_tab(int **tab, t_variables *vars)
{
	int	**clone;
	int i;
	int j;

	i = 0;
	j = 0;
	if (!(clone = (int **)malloc(sizeof(int *) * vars->lines)))
		return (NULL);
	while (i < vars->lines)
	{
		if (!(clone[i] = (int *)malloc(sizeof(int) * vars->width)))
			return (NULL);
		j = 0;
		while (j < vars->width)
		{
			clone[i][j] = tab[i][j];
			j++;
		}
		i++;
	}
	return (clone);
}

int		**solve(int **tab, t_variables *vars)
{
	int j;
	int i;
	int	**clone;

	i = -1;
	clone = copy_tab(tab, vars);
	vars->max = 1;
	while (++i < vars->lines)
	{
		j = -1;
		while (++j < vars->width)
		{
			if (i != 0 && j != 0)
			{
				if (tab[i][j] > 0)
					clone[i][j] = 1 + minimum(clone[i][j - 1],
							clone[i - 1][j], clone[i - 1][j - 1]);
				if (clone[i][j] > vars->max)
					vars->max = clone[i][j];
			}
		}
	}
	ft_free(tab, vars);
	return (clone);
}

void	biggest_square(char **grid, t_variables *vars, int i, int j)
{
	int x_max;
	int y_max;
	int copie_i;

	copie_i = i;
	x_max = vars->max;
	while (x_max > 0)
	{
		y_max = vars->max;
		i = copie_i;
		while (y_max > 0)
		{
			grid[i][j] = vars->filled;
			i--;
			y_max--;
		}
		j--;
		x_max--;
	}
}
