/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:29:11 by lbally            #+#    #+#             */
/*   Updated: 2021/11/29 16:42:20 by bfichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <strings.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include <signal.h>

void	client(char *av, int num);
void	send(int pid, char av);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
void	rep(int num);
void	marche(int sign);
int		convert(char *str);
int		ft_isdigit(int c);
int		convert(char *str);
int		ft_str_isnumeric(char *str);

#endif
