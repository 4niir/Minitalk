/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:52:51 by aboudoun          #+#    #+#             */
/*   Updated: 2022/01/17 18:12:00 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

void	signal_handler(int sign)
{
	static int	c = 0;
	static int	bit = 0;

	if (sign == SIGUSR1)
	{
		c = (c << 1) | 1;
		bit++;
	}
	if (sign == SIGUSR2)
	{
		c = (c << 1);
		bit++;
	}
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
	ft_printf("%d\n", id);
	signals.sa_handler = &signal_handler;
	/*sigemptyset(&signals.sa_mask);
	signals.sa_sigaction = &signal_handler;
	signals.sa_flags = 0;*/
	while (1)
	{
		sigaction(SIGUSR1, &signals, NULL);
		sigaction(SIGUSR2, &signals, NULL);
		pause();
	}
}
