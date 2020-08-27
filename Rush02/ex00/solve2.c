/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 17:57:29 by erlajoua          #+#    #+#             */
/*   Updated: 2020/08/23 23:39:39 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		parse_print(char *str)
{
	int i;
	int len;

	len = ft_strlen(str);
	i = 1;
	if (ft_atoi(str) >= 20 && ft_atoi(str) < 100)
	{
		if ((str[0] >= '0' && str[i] <= '9'))
			if (str[1] != '0')
				return (0);
	}
	else if (len > 2 || ft_strcmp(str, "100") == 0)
	{
		if (str[0] != '1')
			return (0);
		else
		{
			while (str[i] == '0')
				i++;
			if (str[i] != '\0')
				return (0);
		}
	}
	return (1);
}

int		print_nb(char *dico, char *nbstr)
{
	int i;
	int j;
	int max;

	i = -1;
	while (dico[++i] && parse_print(nbstr))
		if (i == 0 || dico[i - 1] == '\n')
		{
			while (dico[i] == ' ' || (dico[i] == '0' && ft_strcmp(nbstr, "0")))
				i++;
			if (ft_strcmp_m(&dico[i], nbstr))
			{
				j = 0;
				while (dico[i] == nbstr[j++])
					i++;
				while (dico[i + 1] == ' ' || dico[i + 1] == ':')
					i++;
				max = trim_zero(dico, i);
				while (++i < max)
					ft_putchar(dico[i]);
				return (1);
			}
		}
	return (0);
}

void	sort_3(char *dico, long long nb)
{
	if (print_nb(dico, nbnb) == 0)
	{
		if (nb > 20 && nb < 100)
		{
			sort_3(dico, ((nb / 10) * 10));
			if (nb % 10 != 0)
			{
				ft_putchar(' ');
				sort_3(dico, (nb % 10));
			}
		}
		if (nb >= 100 && nb < 1000)
		{
			sort_3(dico, (nb / 100));
			ft_putchar(' ');
			sort_3(dico, (100));
			if (nb % 100 != 0)
			{
				ft_putchar(' ');
				sort_3(dico, (nb % 100));
			}
		}
	}
	free(nbnb);
}
