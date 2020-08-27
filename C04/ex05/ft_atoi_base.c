/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 13:57:46 by erlajoua          #+#    #+#             */
/*   Updated: 2020/08/10 15:32:31 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		pos_inbase(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int		check_base(char *base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (base[i])
	{
		j = i + 1;
		while ((base[i] != base[j]) && base[j])
			j++;
		if (base[j] != '\0')
			return (0);
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == 32)
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int ret;
	int sign;
	int size_base;

	i = 0;
	ret = 0;
	sign = 1;
	size_base = check_base(base);
	if (size_base == 0)
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && pos_inbase(*str, base) != -1)
	{
		ret = ret * size_base + pos_inbase(*str, base);
		str++;
	}
	return (ret * sign);
}
