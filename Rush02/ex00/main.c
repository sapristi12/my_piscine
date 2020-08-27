/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtellenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 23:18:18 by vtellenn          #+#    #+#             */
/*   Updated: 2020/08/23 23:39:28 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		size;
	char	tmp;

	i = 0;
	size = ft_strlen(str);
	while (i < size - 1)
	{
		tmp = str[size - 1];
		str[size - 1] = str[i];
		str[i] = tmp;
		i++;
		size--;
	}
	return (str);
}

int		check_fd(int fd)
{
	if (fd == -1)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	dico[BUF_SIZE];
	int		arg;

	arg = 1;
	if (argc < 2 && argc > 3)
		return (0);
	if (argc == 2)
		fd = open("numbers.dict", O_RDONLY);
	else
	{
		fd = open(argv[1], O_RDONLY);
		arg = 2;
	}
	if (check_fd(fd) == 0)
		return (0);
	ret = read(fd, dico, BUF_SIZE);
	dico[ret] = '\0';
	if (!parsing(argv[arg], dico))
		write(1, "Error\n", 6);
	else
		stock_packages(dico, argv[arg]);
	close(fd);
	return (0);
}
