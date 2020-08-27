/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 09:21:41 by erlajoua          #+#    #+#             */
/*   Updated: 2020/08/27 14:25:28 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <libgen.h>
#include <string.h>
#include <errno.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

void	ft_error(char *str, char *base)
{
	int i;

	i = 0;
	ft_putstr(basename(base));
	ft_putstr(": ");
	ft_putstr(str);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	ft_putstr("\n");
}

void	ft_cat(int ac, char **av)
{
	int		i;
	char	buff;
	int		fd;
	int		bytes;

	i = 0;
	while (++i < ac)
	{
		fd = open(av[i], O_RDONLY);
		if (fd >= 0)
			while ((bytes = read(fd, &buff, 1)) != 0)
			{
				if (bytes == -1)
				{
					ft_error(av[i], av[0]);
					break ;
				}
				write(1, &buff, 1);
			}
		else
			ft_error(av[i], av[0]);
		close(fd);
	}
}

void	manual(void)
{
	char	buff;

	while (read(0, &buff, 1) != 0)
		write(1, &buff, 1);
}

int		main(int ac, char **av)
{
	if (ac < 2 || av[1][0] == '-')
		manual();
	ft_cat(ac, av);
	return (0);
}
