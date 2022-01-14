#include"minitalk.h"

static int check_error(int argc, char **argv, int pid)
{
	int i;

	i = 0;
	while(argv[1][i])
	{
		if(!ft_strchr("0123456789", argv[1][i]))
			exit(1);
		i++;
	}
	if (argc != 3 || pid < 0)
		exit(1);
	
}

int		main(int argc, char **argv)
{
	int pid;
	char *str;

	pid = ft_atoi(argv[1]);
	check_error(argc, argv, pid);
}