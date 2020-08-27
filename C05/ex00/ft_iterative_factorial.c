/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 08:24:10 by erlajoua          #+#    #+#             */
/*   Updated: 2020/08/11 10:11:42 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int ret;

	ret = 1;
	if (nb < 0)
		return (0);
	if (nb >= 0)
	{
		while (nb > 0)
		{
			ret = ret * nb;
			nb--;
		}
	}
	return (ret);
}
