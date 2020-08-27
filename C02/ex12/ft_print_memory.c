/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 19:19:02 by erlajoua          #+#    #+#             */
/*   Updated: 2020/08/08 11:45:33 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_ok(long addr, int i)
{
	char *basehexa;

	basehexa = "0123456789abcdef";
	if (!addr)
	{
		while (i < 16)
		{
			ft_putchar('0');
			i++;
		}
		return ;
	}
	print_ok(addr >> 4, i + 1);
	ft_putchar(basehexa[addr % 16]);
}

void	print_the_printables(unsigned char *str)
{
	char	*basehexa;
	int		i;

	i = 0;
	basehexa = "0123456789abcdef";
	while (str[i] && i < 16)
	{
		if (str[i] < 32 || str[i] > 126)
		{
			ft_putchar('.');
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}

void	print_hexa_str(unsigned int i, unsigned char *str, unsigned int size)
{
	unsigned int	j;
	char			*basehexa;

	basehexa = "0123456789abcdef";
	j = 0;
	while (j < 16 && str[j])
	{
		ft_putchar((char)basehexa[(*(str + j) / 16) % 16]);
		ft_putchar((char)basehexa[*(str + j) % 16]);
		if (j % 2)
			ft_putchar(' ');
		j++;
	}
	while (j != 16)
	{
		ft_putchar(' ');
		ft_putchar(' ');
		if (j % 2)
			ft_putchar(' ');
		j++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*str;

	i = 0;
	while (i < size)
	{
		str = (unsigned char *)addr + i;
		print_ok((long)str, 0);
		ft_putchar(':');
		ft_putchar(' ');
		print_hexa_str(i, str, size);
		ft_putchar(' ');
		ft_putchar(' ');
		print_the_printables(str);
		ft_putchar('\n');
		i += 16;
	}
	return (addr);
}
