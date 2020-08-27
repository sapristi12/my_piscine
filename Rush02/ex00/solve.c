/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 01:30:20 by vintran           #+#    #+#             */
/*   Updated: 2020/08/23 22:33:01 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		trim_zero(char *dico, int i)
{
	while (dico[i + 1] != '\n' && dico[i + 1] != '\0')
		i++;
	while (i >= 0 && dico[i - 1] != '\n' && dico[i] == ' ')
		i--;
	return (i + 1);
}

void	modulo1(char *tab, char nbstr, int *i, int *j)
{
	tab[0] = '0';
	tab[1] = '0';
	tab[2] = nbstr;
	*i = *i + 1;
	*j = *j + 1;
}

void	modulo2(char *tab, char *nbstr, int *i, int *j)
{
	tab[0] = '0';
	tab[1] = nbstr[0];
	tab[2] = nbstr[1];
	*i = *i + 2;
	*j = *j + 1;
}

void	create_str(char **tab, char *nbstr, int *i, int *j)
{
	int k;

	k = 0;
	while (k < 3)
	{
		tab[*j][k] = nbstr[*i];
		k++;
		*i = *i + 1;
	}
	*j = *j + 1;
}

char	**create_package(char *nbstr, int len, int nbpack)
{
	char	**tab;
	int		j;
	int		i;
	int		k;

	j = 0;
	i = 0;
	k = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * nbpack)))
		return (NULL);
	while (k < nbpack)
	{
		if (!(tab[k] = (char *)malloc(sizeof(char) * 4)))
			return (NULL);
		tab[k][3] = '\0';
		k++;
	}
	if (len % 3 == 1)
		modulo1(tab[j], nbstr[0], &i, &j);
	if (len % 3 == 2)
		modulo2(tab[j], nbstr, &i, &j);
	while (j < nbpack)
		create_str(tab, nbstr, &i, &j);
	return (tab);
}
