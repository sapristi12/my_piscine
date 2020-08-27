/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_comb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 11:25:13 by erlajoua          #+#    #+#             */
/*   Updated: 2020/08/16 12:55:47 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int		double_char(char *comb)
{
	int i;
	int j;

	i = 0;
	while (comb[i])
	{
		j = i + 1;
		while (comb[j])
		{
			if (comb[i] == comb[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		string_is_validl(char *comb, int pos_index, char val_index[17])
{
	int i;
	int count;
	int min;

	i = 0;
	count = 1;
	if (double_char(comb) == 0)
		return (0);
	if ((pos_index >= 0 && pos_index <= 3) ||
			(pos_index >= 8 && pos_index <= 11))
	{
		min = comb[0];
		while (i < 3)
		{
			if (comb[0] < comb[i + 1] && min < comb[i + 1])
			{
				min = comb[i + 1];
				count++;
			}
			i++;
		}
	}
	if (count + 48 == val_index[pos_index])
		return (1);
	return (0);
}

int		string_is_validr(char *comb, int pos_index, char val_index[17])
{
	int i;
	int count;
	int max;

	if (double_char(comb) == 0)
		return (0);
	i = 3;
	count = 1;
	if ((pos_index >= 4 && pos_index <= 7) ||
			(pos_index >= 12 && pos_index <= 15))
	{
		max = comb[3];
		while (i > 0)
		{
			if (comb[3] < comb[i - 1] && max < comb[i - 1])
			{
				max = comb[i - 1];
				count++;
			}
			i--;
		}
	}
	if (count + 48 == val_index[pos_index])
		return (1);
	return (0);
}
