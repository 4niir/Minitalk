/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:52:51 by aboudoun          #+#    #+#             */
/*   Updated: 2022/01/18 23:12:56 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

void	signal_handler(int sign, siginfo_t *info, void *(v))
{
	static int	c = 0;
	static int	bit = 0;

	(void)v;
	c = (c << 1) | (sign == SIGUSR1);
	bit++;
	if (bit == 8)
	{
		if (c == 0)
			kill(info -> si_pid, SIGUSR1);
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
	//signals.sa_handler = &signal_handler;
	//sigemptyset(&signals.sa_mask);
	signals.sa_sigaction = &signal_handler;
	//signals.sa_flags = 0;*/
	while (1)
	{
		sigaction(SIGUSR1, &signals, NULL);
		sigaction(SIGUSR2, &signals, NULL);
		pause();
	}
}
