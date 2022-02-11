/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:50:17 by aboudoun          #+#    #+#             */
/*   Updated: 2022/02/11 18:57:12 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

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
}

int	main(int argc, char **argv)
{
	int	id;

	id = ft_atoi(argv[1]);
	check_error(argc, argv);
	send_signal(id, argv[2]);
	return (0);
}
