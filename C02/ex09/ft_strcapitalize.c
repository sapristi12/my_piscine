/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 11:06:08 by erlajoua          #+#    #+#             */
/*   Updated: 2020/08/08 11:38:20 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_alphanum(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

char	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int flag;
	int i;

	flag = 0;
	i = 0;
	ft_strlowcase(str);
	while (str[i])
	{
		while (str[i] && !is_alphanum(str[i]))
			i++;
		if (str[i] && is_alphanum(str[i]))
		{
			flag = 1;
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32;
			while (str[i] && is_alphanum(str[i]) && flag == 1)
			{
				i++;
			}
			flag = 0;
		}
	}
	return (str);
}
