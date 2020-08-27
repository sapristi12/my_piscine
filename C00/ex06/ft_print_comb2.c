/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 10:10:10 by erlajoua          #+#    #+#             */
/*   Updated: 2020/08/06 10:10:43 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	show_nb(int a, int b)
{
	ft_putchar(a / 10 + '0');
	ft_putchar(a % 10 + '0');
	ft_putchar(32);
	ft_putchar(b / 10 + '0');
	ft_putchar(b % 10 + '0');
	if (a != 98 || b != 99)
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			show_nb(a, b);
			b++;
		}
		a++;
	}
}
