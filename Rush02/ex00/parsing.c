/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtellenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 23:17:15 by vtellenn          #+#    #+#             */
/*   Updated: 2020/08/23 23:18:38 by vtellenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		is_only_zero(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] == '0')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

int		parsing(char *str, char *dico)
{
	int i;
	int size;
	int zero;

	zero = 0;
	while (str[zero] == '0')
		zero++;
	size = ft_strlen(&str[zero]);
	if ((str[0] == '0' && str[1] == '\0') || is_only_zero(str))
		print_nb(dico, "0");
	if (size > 39)
		return (0);
	i = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}
