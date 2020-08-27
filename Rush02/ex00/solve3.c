/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 18:27:29 by erlajoua          #+#    #+#             */
/*   Updated: 2020/08/23 22:38:40 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_comp100(char **tab, int *i, char *dico, int nbpack)
{
	int j;

	sort_3(dico, ft_atoi(tab[*i]));
	if (*i < nbpack - 1)
	{
		ft_putchar(' ');
		print_nb(dico, fill_zero(nbpack - *i - 1));
		j = *i;
		while (j + 1 < nbpack && ft_strcmp(tab[j + 1], "000") == 0)
			j++;
		if (j != nbpack - 1)
			ft_putchar(' ');
	}
}

void	free_all(char **tab, int nbpack)
{
	int i;

	i = 0;
	while (i < nbpack)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	triple_show(char *dico)
{
	print_nb(dico, "1");
	ft_putchar(' ');
	print_nb(dico, "100");
}

void	solve(char **tab, char *dico, int nbpack, int i)
{
	int j;

	while (++i < nbpack)
	{
		if (!ft_strcmp(tab[i], "100"))
		{
			triple_show(dico);
			if (i < nbpack - 1)
			{
				ft_putchar(' ');
				print_nb(dico, fill_zero(nbpack - i - 1));
				j = i;
				while (j + 1 < nbpack && ft_strcmp(tab[j + 1], "000") == 0)
					j++;
				if (j != nbpack - 1)
					ft_putchar(' ');
			}
			if (i + 1 < nbpack)
				i++;
			else
				break ;
		}
		if (ft_strcmp(tab[i], "000"))
			ft_comp100(tab, &i, dico, nbpack);
	}
}

char	**stock_packages(char *dico, char *nbstr)
{
	int		len;
	char	**tab;
	int		mod;
	int		nbpack;

	len = ft_strlen(nbstr);
	nbpack = len / 3;
	mod = len % 3;
	if (mod)
		nbpack++;
	tab = create_package(nbstr, len, nbpack);
	solve(tab, dico, nbpack, -1);
	write(1, "\n", 1);
	free_all(tab, nbpack);
	return (tab);
}
