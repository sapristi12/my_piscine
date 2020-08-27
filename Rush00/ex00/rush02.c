/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-merr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 10:53:44 by jle-merr          #+#    #+#             */
/*   Updated: 2020/08/09 16:37:10 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	horizontal_print(char start, char corpse, char end, int size)
{
	int i;

	i = 1;
	while (i <= size)
	{
		if (i == 1)
			ft_putchar(start);
		else if (i == size)
			ft_putchar(end);
		else
			ft_putchar(corpse);
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
			horizontal_print('A', 'B', 'A', x);
		else if (i == y)
			horizontal_print('C', 'B', 'C', x);
		else
			horizontal_print('B', ' ', 'B', x);
		ft_putchar('\n');
		i++;
	}
}
