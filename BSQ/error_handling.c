/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 17:42:32 by malatini          #+#    #+#             */
/*   Updated: 2020/08/26 19:49:32 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	map_error(void)
{
	write(2, "map error\n", 10);
}

int		**intint_map_error(void)
{
	write(2, "map error\n", 10);
	return (0);
}
