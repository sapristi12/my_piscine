/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 10:19:48 by erlajoua          #+#    #+#             */
/*   Updated: 2020/08/13 16:43:58 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int		ft_count_char(int size, char **strs, char *sep)
{
	int i;
	int total;

	total = 0;
	i = 0;
	while (i < size)
	{
		total += ft_strlen(strs[i]);
		i++;
	}
	total += ft_strlen(sep) * size - 1;
	return (total + 1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len;
	char	*dest;
	int		i;

	i = 0;
	len = ft_count_char(size, strs, sep);
	if (size < 0)
		dest = (char *)malloc(1);
	else
		dest = (char *)malloc(sizeof(char) * len);
	if (!dest)
		return (NULL);
	*dest = '\0';
	len = 0;
	while (i < size)
	{
		dest = ft_strcat(dest, strs[i]);
		dest = (i < size - 1) ? ft_strcat(dest, sep) : dest;
		i++;
	}
	return (dest);
}
