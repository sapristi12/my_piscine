/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 09:57:46 by erlajoua          #+#    #+#             */
/*   Updated: 2020/08/08 11:46:27 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_hexnumber(unsigned char c)
{
	char *basehexa;

	basehexa = "0123456789abcdef";
	if (c < 16)
	{
		ft_putchar('0');
		ft_putchar(basehexa[c]);
	}
	else
	{
		ft_putchar(basehexa[c / 16]);
		ft_putchar(basehexa[c % 16]);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] > 126)
		{
			ft_putchar('\\');
			print_hexnumber(str[i]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
