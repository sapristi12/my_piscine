/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 20:46:15 by erlajoua          #+#    #+#             */
/*   Updated: 2020/08/26 19:47:52 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	free_int_tab(int **tab, t_variables *vars)
{
	int i;

	i = 0;
	while (i < vars->lines)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_char_tab(char **grid, t_variables *vars)
{
	int i;

	i = 0;
	while (i < vars->lines)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

void	ft_free(int **tab, t_variables *vars)
{
	int i;

	i = 0;
	while (i < vars->lines)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**init_grid(t_variables *vars)
{
	char	**grid;
	int		i;

	i = 0;
	if (!(grid = (char **)malloc(sizeof(char *) * vars->lines)))
		return (NULL);
	while (i < vars->lines)
	{
		if (!(grid[i] = (char *)malloc(sizeof(char) * vars->width)))
			return (NULL);
		i++;
	}
	return (grid);
}
