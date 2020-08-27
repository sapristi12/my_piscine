/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtellenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 23:09:57 by vtellenn          #+#    #+#             */
/*   Updated: 2020/08/23 23:10:07 by vtellenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int				ft_strcmp_m(char *dico, char *nbstr)
{
	int i;

	i = 0;
	while (dico[i] == nbstr[i])
	{
		if ((dico[i + 1] == ':' || dico[i + 1] == ' ') && nbstr[i + 1] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int				ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

long long		ft_atoi(char *str)
{
	long long	result;
	int			sign;
	int			i;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == '\f' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\r' || str[i] == '\v' || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

char			*ft_itoa(long long nb)
{
	int				i;
	char			*res;
	int				length;
	long long		nb2;

	nb2 = nb;
	length = 0;
	i = 0;
	while (nb2)
	{
		nb2 = nb2 / 10;
		length++;
	}
	if (!(res = malloc(sizeof(*res) * (length + 1))))
		return (NULL);
	res[length--] = '\0';
	while (length >= 0)
	{
		res[length] = nb % 10 + '0';
		length--;
		nb /= 10;
	}
	return (res);
}
