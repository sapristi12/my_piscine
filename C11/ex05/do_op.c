/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 11:14:00 by erlajoua          #+#    #+#             */
/*   Updated: 2020/08/20 20:09:12 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int		pre_modulo(int nb1, int nb2)
{
	int ret;

	ret = 0;
	if (nb2 != 0)
	{
		ret = modulo(nb1, nb2);
		return (ret);
	}
	else
	{
		ft_putstr("Stop : modulo by zero\n");
		return (0);
	}
}

int		pre_division(int nb1, int nb2)
{
	int ret;

	ret = 0;
	if (nb2 != 0)
	{
		ret = division(nb1, nb2);
		return (ret);
	}
	else
	{
		ft_putstr("Stop : division by zero\n");
		return (0);
	}
}

int		main(int ac, char **av)
{
	int nb1;
	int nb2;
	int ret;

	ret = 0;
	if (ac != 4)
		return (0);
	nb1 = ft_atoi(av[1]);
	nb2 = ft_atoi(av[3]);
	if (av[2][0] == '+')
		ret = addition(nb1, nb2);
	else if (av[2][0] == '-')
		ret = soustraction(nb1, nb2);
	else if (av[2][0] == '*')
		ret = multiplication(nb1, nb2);
	else if (av[2][0] == '/')
		ret = pre_division(nb1, nb2);
	else if (av[2][0] == '%')
		ret = pre_modulo(nb1, nb2);
	if ((av[2][0] == '/' && nb2 == 0) || (av[2][0] == '%' && nb2 == 0))
		return (0);
	ft_putnbr(ret);
	write(1, "\n", 1);
	return (0);
}
