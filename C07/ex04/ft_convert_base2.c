/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 10:56:34 by erlajoua          #+#    #+#             */
/*   Updated: 2020/08/13 21:32:07 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		check_base(char *base);

char	*itoa_base(int value, char *base)
{
	unsigned int	nb;
	unsigned int	nb2;
	int				i;
	int				size_base;
	char			*dest;

	i = 0;
	size_base = check_base(base);
	nb = (value >= 0) ? value : -value;
	nb2 = (value >= 0) ? value : -value;
	i = (value >= 0) ? 1 : 2;
	while (nb2 / size_base >= 1)
	{
		nb2 = nb2 / size_base;
		i++;
	}
	dest = (char *)malloc(sizeof(char) * i + 1);
	dest[i] = '\0';
	while (i--)
	{
		dest[i] = base[nb % size_base];
		nb = nb / size_base;
	}
	(value < 0) ? dest[i + 1] = '-' : 0;
	return (dest);
}
