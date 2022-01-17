#include"minitalk.h"

void	signal_handler(int sign)
{ 
	static int c = 0;
	static int bit = 0;
	int s;
	
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
	//	str[8] = '\0';
		write(1, &c, 1);
		bit = 0;
		c = 0;
	}
	// if (sign == SIGUSR1)
	// {
	// 	ft_printf("1");
	// }
	
	// else if (sign == SIGUSR2)
	// {
	// 	ft_printf("0");
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
