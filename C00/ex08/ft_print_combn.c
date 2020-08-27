/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 10:14:15 by erlajoua          #+#    #+#             */
/*   Updated: 2020/08/06 10:37:52 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	show_number(int *number, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putchar(number[i] + '0');
		i++;
	}
	if (number[0] != 10 - n)
		write(1, ", ", 2);
}

void	config_nb(int *number, int n, int *i, int *k)
{
	if (number[0] == 10 - n)
		return ;
	while (number[n - 1 - *i] == *k)
	{
		*i = *i + 1;
		*k = *k - 1;
		if (number[n - 1 - *i] < *k)
		{
			number[n - 1 - *i]++;
			while (*i > 0)
			{
				number[n - *i] = number[n - 1 - *i] + 1;
				*i = *i - 1;
			}
			break ;
		}
	}
}

void	fill_tab(int *tab, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		tab[i] = i;
		i++;
	}
}

void	ft_print_combn(int n)
{
	int number[10];
	int i;
	int k;

	i = 0;
	fill_tab(number, n);
	while (number[0] <= 10 - n)
	{
		k = 9;
		i = 0;
		show_number(number, n);
		if (number[0] == 10 - n)
			break ;
		if (number[n - 1] == 9)
		{
			config_nb(number, n, &i, &k);
		}
		else
			number[n - 1]++;
	}
}
