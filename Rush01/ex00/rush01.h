/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 11:17:45 by erlajoua          #+#    #+#             */
/*   Updated: 2020/08/16 23:38:56 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <stdlib.h>
# include <unistd.h>

int		nb_comb(int val_index);
char	*comb1(int ptr);
char	*comb3(int ptr);
char	*comb4(int ptr);
void	show_tab(char **tab);
int		string_is_validr(char *comb, int pos_index, char val_index[17]);
int		string_is_validl(char *comb, int pos_index, char val_index[17]);
char	*get_string(char char_index, int ptr);
void	remove_string(char **tab, int pos_index);
void	place_string(char **tab, char *comb, int pos_index);
char	*get_placed(char **tab, int pos_index);
char	*recup_comb(char val_index[17], char **tab, int pos_index, int ptr);
int		stop_condition(int *pos_index, char **tab, char *comb);
void	cancel_backtrack(char **tab, int pos_index,
		char val_index[17], int *ptr);
char	*select_comb2(char *dest, char **strs, int ptr);
char	*comb2(int ptr);
int		solve(int pos_index, char val_index[17], int *ptr, char **tab);
int		double_char(char *comb);
char	*get_str(char *str);
int		ft_is_valid(char *str, int size);
char	**init_tab(void);

#endif
