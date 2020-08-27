/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 18:40:28 by malatini          #+#    #+#             */
/*   Updated: 2020/08/27 10:26:26 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int				get_length(char *str)
{
	int i;
	int nb_of_lines;

	i = 0;
	nb_of_lines = ft_s_atoi(str);
	return (nb_of_lines);
}

int				get_chars(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

char			get_empty_char(char *str)
{
	char	empty_char;
	int		i;

	i = get_chars(str) - 3;
	empty_char = str[i];
	if (empty_char >= 32 && empty_char <= 126)
		return (empty_char);
	return (0);
}

char			get_obstacle_char(char *str)
{
	char	obstacle_char;
	int		i;

	i = get_chars(str) - 2;
	obstacle_char = str[i];
	if (obstacle_char >= 32 && obstacle_char <= 126)
		return (obstacle_char);
	return (0);
}

char			get_filled_char(char *str)
{
	char	filled_char;
	int		i;

	i = get_chars(str) - 1;
	filled_char = str[i];
	if (filled_char >= 32 && filled_char <= 126)
		return (filled_char);
	return (0);
}
