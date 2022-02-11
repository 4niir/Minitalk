/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:52:51 by aboudoun          #+#    #+#             */
/*   Updated: 2022/02/11 21:38:22 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

static void	signal_handler(int sign, siginfo_t *info, void *context)
{
	static int	c = 0;
	static int	bit = 0;
	static int	client_pid;

	(void)context;
	if (client_pid != info -> si_pid)
	{
		c = 0;
		bit = 0;
		client_pid = info->si_pid;
	}
	c = (c << 1) | (sign == SIGUSR1);
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	int					id;
	struct sigaction	signals;

	id = (int) getpid();
	ft_printf("server id : %d\n", id);
	signals.sa_sigaction = &signal_handler;
	while (1)
	{
		sigaction(SIGUSR1, &signals, NULL);
		sigaction(SIGUSR2, &signals, NULL);
		pause();
	}
	return (0);
}
