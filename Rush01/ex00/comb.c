/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 11:19:02 by erlajoua          #+#    #+#             */
/*   Updated: 2020/08/16 23:37:49 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int		nb_comb(int val_index)
{
	val_index -= 48;
	if (val_index == 4)
		return (1);
	else if (val_index == 3)
		return (6);
	else if (val_index == 2)
		return (11);
	else if (val_index == 1)
		return (6);
	return (0);
}

char	*comb1(int ptr)
{
	int		i;
	char	**strs;
	char	*dest;

	i = 0;
	if (!(dest = (char *)malloc(sizeof(char) * 5)))
		return (NULL);
	if (!(strs = (char **)malloc(sizeof(char *) * 6)))
		return (NULL);
	while (i < 6)
	{
		if (!(strs[i] = (char *)malloc(sizeof(char) * 5)))
			return (NULL);
		i++;
	}
	strs[0] = "4123";
	strs[1] = "4132";
	strs[2] = "4321";
	strs[3] = "4213";
	strs[4] = "4312";
	strs[5] = "4231";
	dest = strs[ptr];
	free(strs);
	return (dest);
}

char	*comb3(int ptr)
{
	int		i;
	char	**strs;
	char	*dest;

	i = 0;
	if (!(dest = (char *)malloc(sizeof(char) * 5)))
		return (NULL);
	if (!(strs = (char **)malloc(sizeof(char *) * 6)))
		return (NULL);
	while (i < 6)
	{
		if (!(strs[i] = (char *)malloc(sizeof(char) * 5)))
			return (NULL);
		i++;
	}
	strs[0] = "2134";
	strs[1] = "1342";
	strs[2] = "2341";
	strs[3] = "1243";
	strs[4] = "2314";
	strs[5] = "1324";
	dest = strs[ptr];
	free(strs);
	return (dest);
}

char	*comb4(int ptr)
{
	char **strs;
	char *dest;

	if (!(dest = (char *)malloc(sizeof(char) * 5)))
		return (NULL);
	if (!(strs = (char **)malloc(sizeof(char *) * 1)))
		return (NULL);
	if (!(strs[0] = (char *)malloc(sizeof(char) * 5)))
		return (NULL);
	strs[0] = "1234";
	dest = strs[ptr];
	free(strs);
	return (dest);
}
