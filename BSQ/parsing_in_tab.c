/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_in_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:26:24 by malatini          #+#    #+#             */
/*   Updated: 2020/08/27 10:39:39 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		loop_sub(char **line, t_variables *vars, int **tab, int *line_pos)
{
	if (*line_pos == 0)
		vars->width = ft_strlen(*line);
	else if (ft_strlen(*line) != vars->width)
		return (1);
	if (!(tab[(*line_pos)++] = convert_line(*line, vars->i, vars))
			|| vars->lines < *line_pos)
		return (1);
	free(*line);
	vars->i = 0;
	if (!(*line = malloc(1)))
		return (1);
	(*line)[0] = 0;
	return (0);
}

int		**loop_in_lines(int fd, t_variables *vars, int **tab)
{
	char	c;
	int		bytes_read;
	char	*line;
	int		line_pos;

	if (!(line = malloc(sizeof(char))))
		return (NULL);
	vars->i = 0;
	line_pos = 0;
	while ((bytes_read = read(fd, &c, 1)) != 0)
	{
		if (bytes_read == -1)
			return (0);
		if (c == '\n')
		{
			if (loop_sub(&line, vars, tab, &line_pos))
				return (intint_map_error());
		}
		else
			line = tom_strjoin(line, c, vars->i++);
	}
	if (line_pos != vars->lines || vars->lines == 0)
		return (intint_map_error());
	free(line);
	return (tab);
}

int		**store_lines(int size)
{
	int **tab;
	int i;

	if (!(tab = malloc(sizeof(int*) * size)))
		return (NULL);
	i = 0;
	return (tab);
}

int		*convert_line(char *line, int size, t_variables *vars)
{
	int i;
	int *tab;

	if (!(tab = malloc(size * sizeof(int))))
		return (NULL);
	i = 0;
	while (line[i])
	{
		if (line[i] == vars->empty)
			tab[i] = 1;
		else if (line[i] == vars->obstacle)
			tab[i] = 0;
		else
			return (NULL);
		++i;
	}
	return (tab);
}
