#include"minitalk.h"

// void	signal_handler(int sign)
// {
// 	int len;
// 	char str[8];

// 	len = 0;
// 	str[8] = '\0';
// 	if (sign == SIGUSR1)
// 		str[len++] = '0';
// 	if (sign == SIGUSR2)
// 		str[len++] = '1';
// 	if (len == 8)
// 	{
// 		atoibase(str);
// 		print(the character);
// 	}
// }
void	signal_handler(int sig, siginfo_t *info, void *(v))
{
	static int	character;
	static int	client_pid;
	static int	i;

	(void)v;
	if ((client_pid != info->si_pid && i != 0))
	{
		i = 0;
		character = 0;
	}
	character = (character << 1) | ((sig - SIGUSR1) ^ 1);
	i++;
	if (i == 8)
	{
		if (character == 0)
			kill(info ->si_pid, SIGUSR1);
		else
			write(1, &character, 1);
		character = 0;
		i = 0;
	}
	client_pid = info -> si_pid;
}

int main()
{
	int Pid;
	struct sigaction s_a;

	Pid = (int) getpid();
	ft_printf("%d\n", Pid);
	//sigemptyset(&s_a.sa_mask);
	s_a.sa_sigaction = &signal_handler;
	//s_a.sa_flags = 0;
	//s_a.sa_handler = signal_handler;
	sigaction(SIGUSR1, &s_a, NULL);
	sigaction(SIGUSR2, &s_a, NULL);
	while (1)
		pause();
}