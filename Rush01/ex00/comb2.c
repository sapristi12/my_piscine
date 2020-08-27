/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 23:35:45 by vintran           #+#    #+#             */
/*   Updated: 2020/08/16 23:37:57 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

char	*select_comb2(char *dest, char **strs, int ptr)
{
	dest = strs[ptr];
	free(strs);
	return (dest);
}

char	*comb2(int ptr)
{
	int		i;
	char	**strs;
	char	*dest;

	i = -1;
	if (!(dest = (char *)malloc(sizeof(char) * 5)))
		return (NULL);
	if (!(strs = (char **)malloc(sizeof(char *) * 11)))
		return (NULL);
	while (++i < 11)
		if (!(strs[i] = (char *)malloc(sizeof(char) * 5)))
			return (NULL);
	strs[0] = "1432";
	strs[1] = "1423";
	strs[2] = "2413";
	strs[3] = "2431";
	strs[4] = "2143";
	strs[5] = "3142";
	strs[6] = "3214";
	strs[7] = "3241";
	strs[8] = "3412";
	strs[9] = "3421";
	strs[10] = "3124";
	return (select_comb2(dest, strs, ptr));
}
