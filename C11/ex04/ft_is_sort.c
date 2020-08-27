/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 22:39:22 by erlajoua          #+#    #+#             */
/*   Updated: 2020/08/20 10:54:26 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < length - 1)
	{
		if (count == 0)
			count = f(tab[i], tab[i + 1]);
		else if (count < 0 && f(tab[i], tab[i + 1]) > 0)
			return (0);
		else if (count > 0 && f(tab[i], tab[i + 1]) < 0)
			return (0);
		i++;
	}
	return (1);
}
