/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 14:32:31 by malatini          #+#    #+#             */
/*   Updated: 2020/08/27 12:40:31 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		get_fd(int ac, char **av)
{
	int fd;

	fd = 0;
	if (ac == 1)
		fd = STDIN_FILENO;
	else if (ac >= 2)
		fd = open(av[ac - 1], O_RDONLY);
	if (fd == -1)
		return (-1);
	else
		return (fd);
}

void	launch(char *line, int fd)
{
	int				**tab;
	t_variables		*vars;

	if (!(vars = store_map_variables(line)))
	{
		map_error();
		return ;
	}
	tab = store_lines(vars->lines);
	if (!(loop_in_lines(fd, vars, tab)))
		return ;
	tab = solve(tab, vars);
	if (vars->lines < 1)
		return (map_error());
	if (vars->width < 1)
		return (map_error());
	fill_map(tab, vars);
	free_int_tab(tab, vars);
	free(vars);
}

void	roulette(int fd)
{
	char			c;
	int				bytes_read;
	char			*line;
	int				i;

	if (!(line = malloc(1)))
		return ;
	line[0] = 0;
	i = 0;
	while ((bytes_read = read(fd, &c, 1)))
	{
		if (bytes_read == -1 || !c)
			return (map_error());
		if (c == '\n')
			break ;
		line = tom_strjoin(line, c, i++);
	}
	launch(line, fd);
	close(fd);
}

int		main(int ac, char **av)
{
	int i;
	int fd;

	i = 0;
	while (++i < ac)
	{
		fd = get_fd(i + 1, av);
		if (fd == -1)
			write(2, "map error\n", 10);
		else
			roulette(fd);
		if (i != ac - 1)
			write(1, "\n", 1);
	}
	if (ac == 1)
	{
		fd = STDIN_FILENO;
		roulette(fd);
	}
	return (0);
}
