/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 18:34:44 by malatini          #+#    #+#             */
/*   Updated: 2020/08/27 10:29:42 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef	struct	s_variables
{
	int			lines;
	int			width;
	int			max;
	char		empty;
	char		obstacle;
	char		filled;
	int			i;
}				t_variables;

int				**loop_in_lines(int fd, t_variables *vars, int **tab);
void			map_error(void);
int				**intint_map_error(void);
int				**store_lines(int size);
int				*convert_line(char *line, int size, t_variables *vars);
char			get_empty_char(char *str);
char			get_obstacle_char(char *str);
char			get_filled_char(char *str);
t_variables		*store_map_variables(char *str);
int				ft_s_atoi(char *str);
int				get_length(char *str);
int				get_chars(char *str);
char			*tom_strjoin(char *str, char c, int size);
int				ft_strlen(char *str);
void			aff_tab(char **tab, t_variables *vars);
int				minimum(int a, int b, int c);
int				**copy_tab(int **tab, t_variables *vars);
int				**solve(int **tab, t_variables *vars);
void			biggest_square(char **grid, t_variables *vars, int i, int j);
void			ft_free(int **tab, t_variables *vars);
void			free_int_tab(int **tab, t_variables *vars);
void			free_char_tab(char **grid, t_variables *vars);
void			ft_free(int **tab, t_variables *vars);
char			**init_grid(t_variables *vars);
void			aff_tab(char **tab, t_variables *vars);
void			fill_map(int **tab, t_variables *vars);

#endif
