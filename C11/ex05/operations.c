/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 11:10:42 by erlajoua          #+#    #+#             */
/*   Updated: 2020/08/19 11:28:10 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int		addition(int a, int b)
{
	return (a + b);
}

int		soustraction(int a, int b)
{
	return (a - b);
}

int		division(int a, int b)
{
	if (b)
		return (a / b);
	return (0);
}

int		multiplication(int a, int b)
{
	return (a * b);
}

int		modulo(int a, int b)
{
	if (b)
		return (a % b);
	return (0);
}
