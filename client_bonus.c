/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:58:54 by aboudoun          #+#    #+#             */
/*   Updated: 2022/02/10 18:58:57 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

static void	signal_handler(int sign)
{
	if (sign == SIGUSR1)
		ft_printf("\nmessage received\n\n");
}

static void	check_error(int argc, char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i])
	{
		if (!ft_strchr("0123456789", argv[1][i]))
		{
			ft_printf("wrong id");
			exit(1);
		}
		i++;
	}
	if (argc != 3)
	{
		ft_printf("usage: ./client <server_pid> \"<text to send>\"");
		exit(1);
	}
}

static void	last_message(int id, int bit)
{
	while (bit)
	{
		kill(id, SIGUSR2);
		usleep(700);
		bit--;
	}
}

static void	send_signal(int id, char *str)
{
	int	i;
	int	bit;

	i = 0;
	while (str[i])
	{
		bit = 8;
		while (bit--)
		{
			if ((str[i] >> bit) & 1)
				kill(id, SIGUSR1);
			else
				kill(id, SIGUSR2);
			usleep(700);
		}
		i++;
	}
	last_message(id, 8);
}

int	main(int argc, char **argv)
{
	int	id;

	signal(SIGUSR1, signal_handler);
	id = ft_atoi(argv[1]);
	check_error(argc, argv);
	send_signal(id, argv[2]);
}
