#include"minitalk.h"

int main()
{
	int Pid;

	Pid = (int) getpid();
	ft_printf("%d\n", Pid);
}