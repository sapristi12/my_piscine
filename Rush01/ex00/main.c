/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 11:40:56 by vintran           #+#    #+#             */
/*   Updated: 2020/08/16 21:17:00 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

char	*recup_comb(char val_index[17], char **tab, int pos_index, int ptr)
{
	char *comb;

	if (pos_index >= 0 && pos_index <= 3)
		comb = get_string(val_index[pos_index], ptr);
	else
		comb = get_placed(tab, pos_index - 8);
	return (comb);
}

int		stop_condition(int *pos_index, char **tab, char *comb)
{
	if (*pos_index >= 4 && *pos_index <= 7)
		*pos_index = *pos_index + 4;
	if (*pos_index + 4 >= 16)
	{
		show_tab(tab);
		tab[4][0] = '6';
		free(comb);
		return (0);
	}
	return (1);
}

void	cancel_backtrack(char **tab, int pos_index,
		char val_index[17], int *ptr)
{
	remove_string(tab, pos_index);
	solve(pos_index, val_index, ptr, tab);
}

int		solve(int pos_index, char val_index[17], int *ptr, char **tab)
{
	int		ptr_zero;
	int		stock_ptr;
	char	*comb;

	comb = NULL;
	ptr_zero = 0;
	if (stop_condition(&pos_index, tab, comb) == 0 || tab[4][0] == '6')
		return (0);
	if (*ptr >= nb_comb(val_index[pos_index]))
		return (0);
	comb = recup_comb(val_index, tab, pos_index, *ptr);
	stock_ptr = ++(*ptr);
	if (string_is_validl(comb, pos_index, val_index) &&
			string_is_validr(comb, pos_index + 4, val_index))
	{
		if (pos_index >= 0 && pos_index <= 3)
			place_string(tab, comb, pos_index);
		if (solve(pos_index + 1, val_index, &ptr_zero, tab))
			return (1);
		if (pos_index >= 0 && pos_index <= 3)
			cancel_backtrack(tab, pos_index, val_index, &stock_ptr);
	}
	else
		solve(pos_index, val_index, &stock_ptr, tab);
	return (0);
}

int		main(int ac, char **av)
{
	int		ptr;
	char	**tab;
	char	*str;

	ptr = 0;
	if (ac != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!(str = get_str(av[1])))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	tab = init_tab();
	solve(0, str, &ptr, tab);
	if (tab[4][0] != '6')
		write(1, "Error\n", 6);
	free(tab);
	free(str);
	return (0);
}
