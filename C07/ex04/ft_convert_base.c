/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 10:57:20 by erlajoua          #+#    #+#             */
/*   Updated: 2020/08/14 11:53:19 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*itoa_base(int value, char *base);

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
	while (base[i])
	{
		j = i + 1;
		while (base[j] && base[j] != base[i])
			j++;
		if (base[j] != '\0')
			return (0);
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == 32)
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	if (i <= 1)
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

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	char	*retstr;

	if (!check_base(base_from) || !check_base(base_to))
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	retstr = itoa_base(nb, base_to);
	return (retstr);
}
