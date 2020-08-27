/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 13:41:46 by erlajoua          #+#    #+#             */
/*   Updated: 2020/08/09 16:37:19 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	horizontal_print(char a, char b, char c, int x)
{
	int i;

	i = 1;
	while (i <= x)
	{
		if (i == 1)
			ft_putchar(a);
		else if (i == x)
			ft_putchar(c);
		else
			ft_putchar(b);
		i++;
	}
}

void	rush(int x, int y)
{
	int i;

	i = 1;
	if (x <= 0 || y <= 0)
		return ;
	while (i <= y)
	{
		if (i == 1)
			horizontal_print('A', 'B', 'C', x);
		else if (i == y)
			horizontal_print('C', 'B', 'A', x);
		else
			horizontal_print('B', ' ', 'B', x);
		ft_putchar('\n');
		i++;
	}
}
