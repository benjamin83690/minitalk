/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfichot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:23:34 by bfichot           #+#    #+#             */
/*   Updated: 2021/11/29 23:01:08 by bfichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	convert(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i *= 10;
		i += *str - '0';
		str++;
	}
	return (i);
}

void	send(int pid, char av)
{
	char	msg;

	msg = 0;
	while (msg < 8)
	{
		if ((av >> msg & 1) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		msg++;
	}
}

void	client(char *av, int num)
{
	int	i;

	i = 0;
	while (av[i])
	{
		send(num, av[i]);
		i++;
	}
	send(num, 0);
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3 || !ft_str_isnumeric(av[1]))
	{
		ft_putstr("client: invalid arguments.\n");
		ft_putstr("correct format: [./client <PID> <STR>].\n");
		exit(EXIT_FAILURE);
	}
	pid = convert(av[1]);
	client(av[2], pid);
}
