/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:50:17 by aboudoun          #+#    #+#             */
/*   Updated: 2022/01/17 18:08:19 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

static void	check_error(int argc, char **argv, int pid)
{
	int	i;

	i = 0;
	while (argv[1][i])
	{
		if (!ft_strchr("0123456789", argv[1][i]))
			exit(1);
		i++;
	}
	if (argc != 3)
		exit(1);
}

int	main(int argc, char **argv)
{
	int		pid;
	int		bit;
	int		i;
	char	*str;

	pid = ft_atoi(argv[1]);
	bit = 8;
	i = 0;
	check_error(argc, argv, pid);
	str = ft_strdup(argv[2]);
	while (str[i])
	{
		bit = 8;
		while (bit--)
		{
			if ((str[i] >> bit) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
		i++;
	}
	free (str);
}
