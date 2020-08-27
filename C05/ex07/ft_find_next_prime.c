/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 13:56:36 by erlajoua          #+#    #+#             */
/*   Updated: 2020/08/11 13:12:50 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	unsigned int i;

	i = 3;
	if (nb < 0)
		return (0);
	if ((nb % 2 == 0 && nb != 2) || nb % 3 == 0)
		return (0);
	while (i * i <= (unsigned int)nb)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	if (ft_is_prime(nb))
		return (nb);
	else if (nb % 2 == 1)
		return (ft_find_next_prime(nb + 2));
	else
		return (ft_find_next_prime(nb + 1));
}
