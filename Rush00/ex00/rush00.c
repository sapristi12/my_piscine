/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 12:39:29 by erlajoua          #+#    #+#             */
/*   Updated: 2020/08/09 16:36:59 by erlajoua         ###   ########.fr       */
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
			horizontal_print('o', '-', 'o', x);
		else if (i == y)
			horizontal_print('o', '-', 'o', x);
		else
			horizontal_print('|', ' ', '|', x);
		ft_putchar('\n');
		i++;
	}
}
