/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 12:34:21 by erlajoua          #+#    #+#             */
/*   Updated: 2020/08/13 16:48:13 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

char	*ft_dupcpy(char *str, char *charset)
{
	int		i;
	char	*dest;

	i = 0;
	while (str[i] && !is_charset(str[i], charset))
		i++;
	dest = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while (str[i] && !is_charset(str[i], charset))
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		count_words(char *str, char *charset)
{
	int count;

	count = 0;
	while (*str)
	{
		while (*str && is_charset(*str, charset))
			str++;
		if (*str && !is_charset(*str, charset))
		{
			count++;
			while (*str && !is_charset(*str, charset))
				str++;
		}
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	int		words;
	int		i;
	char	**tab;

	i = 0;
	words = count_words(str, charset);
	tab = (char **)malloc(sizeof(char *) * words + 1);
	while (*str)
	{
		while (*str && is_charset(*str, charset))
			str++;
		if (*str && !is_charset(*str, charset))
		{
			tab[i] = ft_dupcpy(str, charset);
			i++;
			while (*str && !is_charset(*str, charset))
				str++;
		}
	}
	tab[i] = 0;
	return (tab);
}
