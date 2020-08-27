/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 01:30:49 by vintran           #+#    #+#             */
/*   Updated: 2020/08/23 22:24:29 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define BUF_SIZE 4096

char			*ft_strrev(char *str);
void			ft_putchar(char c);
char			*ft_itoa(long long nb);
long long		ft_atoi(char *str);
void			ft_putchar(char c);
int				ft_strlen(char *str);
void			ft_putstr(char *str);
void			sort_3(char *dico, long long nb);
char			*ft_strcpy_3(char *src, int i);
int				print_nb(char *dico, char *nbstr);
void			solve(char **tab, char *dico, int nbpack, int i);
int				ft_strcmp_m(char *dico, char *nbstr);
void			calcul_nb(char *dico, long long nb, int rank);
int				is_charset(char c, char *charset);
char			*ft_dupcpy(char *str, char *charset);
int				count_words(char *str, char *charset);
char			**ft_split(char *str, char *charset);
int				parsing(char *str, char *dico);
char			*fill_zero(int index);
int				ft_strcmp(char *s1, char *s2);
char			**stock_packages(char *dico, char *nbstr);
char			**create_package(char *nbstr, int len, int nbpack);
void			ft_comp100(char **tab, int *i, char *dico, int nbpack);
void			triple_show(char *dico);
int				trim_zero(char *dico, int i);
void			free_all(char **tab, int nbpack);

#endif
