/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 11:24:35 by erlajoua          #+#    #+#             */
/*   Updated: 2020/08/20 11:24:05 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

# include <unistd.h>

int		ft_atoi(char *str);
int		addition(int a, int b);
int		soustraction(int a, int b);
int		multiplication(int a, int b);
int		division(int a, int b);
int		modulo(int a, int b);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);

#endif
