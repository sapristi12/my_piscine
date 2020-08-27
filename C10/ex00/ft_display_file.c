/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displayfile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 12:10:52 by erlajoua          #+#    #+#             */
/*   Updated: 2020/08/27 14:20:50 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		display_files(char **av)
{
	int		fd;
	char	buffer;

	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (-1);
	while (read(fd, &buffer, 1) > 0)
		write(1, &buffer, 1);
	close(fd);
	return (1);
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		if (ac < 2)
			ft_putstr("File name missing.\n");
		if (ac > 2)
			ft_putstr("Too many arguments.\n");
		return (1);
	}
	if (display_files(av) < 0)
		ft_putstr("Cannot read file.\n");
	return (0);
}
