/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 11:29:09 by erlajoua          #+#    #+#             */
/*   Updated: 2020/08/16 21:00:10 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

char	*get_string(char char_index, int ptr)
{
	char	*dest;

	if (char_index == '1')
		dest = comb1(ptr);
	else if (char_index == '2')
		dest = comb2(ptr);
	else if (char_index == '3')
		dest = comb3(ptr);
	else if (char_index == '4')
		dest = comb4(ptr);
	else
		dest = NULL;
	return (dest);
}

void	remove_string(char **tab, int pos_index)
{
	int i;

	i = 0;
	if (pos_index >= 0 && pos_index <= 3)
	{
		while (i < 4)
		{
			tab[i][pos_index] = '0';
			i++;
		}
	}
	else if (pos_index >= 8 && pos_index <= 11)
	{
		while (i < 4)
		{
			tab[pos_index][i] = '0';
			i++;
		}
	}
}

void	place_string(char **tab, char *comb, int pos_index)
{
	int i;

	i = 0;
	if (pos_index >= 0 && pos_index <= 3)
	{
		while (i < 4)
		{
			tab[i][pos_index] = comb[i];
			i++;
		}
	}
	else if (pos_index >= 8 && pos_index <= 11)
	{
		while (i < 4)
		{
			tab[pos_index][i] = comb[i];
			i++;
		}
	}
}

char	*get_placed(char **tab, int pos_index)
{
	int		i;
	char	*dest;

	if (!(dest = (char *)malloc(sizeof(char) * 5)))
		return (NULL);
	if (pos_index + 8 >= 8 && pos_index + 8 <= 11)
	{
		i = 0;
		while (i < 4)
		{
			dest[i] = tab[pos_index][i];
			i++;
		}
	}
	else if (pos_index >= 12 && pos_index <= 15)
	{
		i = 3;
		while (i >= 0)
		{
			dest[i] = tab[pos_index][i];
			i--;
		}
	}
	dest[4] = '\0';
	return (dest);
}
