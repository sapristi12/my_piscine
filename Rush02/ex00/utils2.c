/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtellenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 23:10:17 by vtellenn          #+#    #+#             */
/*   Updated: 2020/08/23 23:16:11 by vtellenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

char	*fill_zero(int index)
{
	int		i;
	char	*res;
	int		size;

	i = 0;
	size = 3 * index + 1;
	if (!(res = malloc(sizeof(*res) * (size + 1))))
		return (NULL);
	res[size] = '\0';
	size--;
	while (size > 0)
	{
		res[size] = '0';
		size--;
	}
	res[size] = '1';
	return (res);
}
