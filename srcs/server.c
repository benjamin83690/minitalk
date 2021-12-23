/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfichot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:23:00 by bfichot           #+#    #+#             */
/*   Updated: 2021/11/29 16:54:30 by bfichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	rep(int num)
{
	static char				msg;
	static int				bits;

	msg |= (num << bits++);
	if (bits > 7)
	{
		if (msg == '\0')
		{
			ft_putchar('\n');
			ft_putchar(msg);
		}
		else
			ft_putchar(msg);
		bits = 0;
		msg = 0;
	}
}

void	marche(int sign)
{
	if (sign == SIGUSR1)
		rep(0);
	else if (sign == SIGUSR2)
		rep(1);
}

int	main(void)
{
	ft_putstr("PID: ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	signal(SIGUSR1, marche);
	signal(SIGUSR2, marche);
	while (1)
		pause();
}
