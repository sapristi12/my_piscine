/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 14:54:39 by erlajoua          #+#    #+#             */
/*   Updated: 2020/08/09 17:04:10 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!to_find[0])
		return (str);
	while (str[i])
	{
		if (to_find[0] == str[i])
		{
			j = 0;
			while (to_find[j] && to_find[j] == str[i + j])
				j++;
			if (!to_find[j])
				return (&str[i]);
		}
		i++;
	}
	return (NULL);
}
