/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 17:55:46 by vintran           #+#    #+#             */
/*   Updated: 2020/08/16 21:02:08 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	show_tab(char **tab)
{
	int j;
	int i;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (i != 3)
			{
				write(1, &tab[j][i], 1);
				write(1, " ", 1);
			}
			else
				write(1, &tab[j][i], 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
}

char	**init_tab(void)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = -1;
	if (!(tab = (char **)malloc(sizeof(char *) * 5)))
		return (NULL);
	while (++j < 4)
	{
		i = 0;
		if (!(tab[j] = malloc(sizeof(char) * 5)))
			return (NULL);
		while (i < 4)
		{
			tab[j][i] = '0';
			i++;
		}
		tab[j][i] = '\0';
	}
	if (!(tab[4] = malloc(sizeof(char) * 2)))
		return (NULL);
	tab[4][0] = '0';
	tab[4][1] = '\0';
	return (tab);
}

char	*get_str(char *str)
{
	int		i;
	int		j;
	char	*dest;

	i = -1;
	j = -1;
	if (!(dest = (char *)malloc(sizeof(char) * 17)))
		return (NULL);
	while (str[++i])
	{
		if (i % 2 == 0)
		{
			if (str[i] >= '1' && str[i] <= '4')
				dest[++j] = str[i];
			else
				return (NULL);
		}
		else
		{
			if (str[i] != ' ')
				return (NULL);
		}
	}
	dest[++j] = '\0';
	return ((i > 31) ? NULL : dest);
}
