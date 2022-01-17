#include"minitalk.h"

void	signal_handler(int sign)
{
	if (sign == SIGUSR1)
	{
		ft_printf("1");
	}
	
	else if (sign == SIGUSR2)
	{
		ft_printf("0");
	}
	// char str[7];
	// int bit = 0;
	// int s;

	// if (sign == SIGUSR1)
	// {
	// 	str[bit] = '0';
	// 	bit++;
	// }
	// if (sign == SIGUSR2)
	// {
	// 	str[bit] = '1';
	// 	bit++;
	// }
	// if (bit == 7)
	// {
	// 	s = ft_atoi_base(str, 2);
	// 	ft_printf("%c", s);
	// 	bit = 0;
	// }
}

int main(void)
{
	int Pid;
	struct sigaction signals;

	Pid = (int) getpid();
	ft_printf("%d\n", Pid);
	signals.sa_handler = &signal_handler;
	//sigemptyset(&signals.sa_mask);
	//signals.sa_sigaction = &signal_handler;
	//signals.sa_flags = 0;
	while (1)
	{
		sigaction(SIGUSR1, &signals, NULL);
		sigaction(SIGUSR2, &signals, NULL);
		pause();
	}
}
