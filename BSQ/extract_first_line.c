/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_first_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 14:55:30 by malatini          #+#    #+#             */
/*   Updated: 2020/08/27 10:39:23 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int				ft_s_atoi(char *str)
{
	int i;
	int result;

	i = 0;
	result = 0;
	while (!(str[i] >= '0' && str[i] <= '9') && str[i])
		i++;
	while ((str[i] >= '0' && str[i] <= '9') && str[i + 3])
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
}

t_variables		*store_map_variables(char *str)
{
	int				i;
	t_variables		*map;

	if (!(map = malloc(sizeof(t_variables) * 1)))
		return (NULL);
	i = 0;
	map->lines = get_length(str);
	map->empty = get_empty_char(str);
	map->obstacle = get_obstacle_char(str);
	map->filled = get_filled_char(str);
	if (!(map->empty) || !(map->obstacle) || !(map->filled))
		return (0);
	if (map->empty == map->obstacle ||
			map->empty == map->filled || map->filled == map->obstacle)
		map_error();
	free(str);
	return (map);
}

char			*tom_strjoin(char *str, char c, int size)
{
	char	*new;
	int		i;

	if (!(new = malloc(size + 2)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		new[i] = str[i];
		++i;
	}
	new[i++] = c;
	new[i] = 0;
	free(str);
	return (new);
}
