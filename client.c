#include"minitalk.h"

static void check_error(int argc, char **argv, int pid)
{
	int i;

	i = 0;
	while(argv[1][i])
	{
		if(!ft_strchr("0123456789", argv[1][i]))
			exit(1);
		i++;
	}
	if (argc != 3)
		exit(1);
	
}

int		main(int argc, char **argv)
{
	int pid;
	int bit;
	int i;
	char *str;

	pid = ft_atoi(argv[1]);
	bit = 8;
	i = -1;
	check_error(argc, argv, pid);
	str = ft_strdup(argv[2]);
	while(str[++i])
	{
		while(bit--)
		{
			if ((str[i] >> bit) & 1)
				kill(SIGUSR1, pid);
			else
				kill(SIGUSR2, pid);
			usleep(100);
		}
	}
	free(str);
}