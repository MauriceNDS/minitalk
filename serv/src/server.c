#include "minitalk.h"

char	change_byte(char byte, int iteration)
{
	short	changer;

	changer = 128;
	while (iteration--)
		changer *= 0.5;
	byte |= changer;
	return (byte);
}

int	handle_msg(int sig)
{
	static char	counter;
	static char	byte;
	static char	**str;

	if (str == NULL)
		str = str_new();
	if (sig == SIGUSR2)
		byte = change_byte(byte, counter);
	counter++;
	if (counter == 8)
	{
		counter = 0;
		if (!byte)
		{
			ft_putendl(*str);
			free(*str);
			free(str);
			str = NULL;
			return (SUCCESS);
		}
		str = str_cappend(str, byte);
		byte = 0;
	}
	return (MAIN_SUCCESS);
}

int	handle_feedback(int sig)
{
	static char	counter;
	static char	byte;
	static char	**str;

	if (str == NULL)
		str = str_new();
	if (sig == SIGUSR2)
		byte = change_byte(byte, counter);
	counter++;
	if (counter == 8)
	{
		counter = 0;
		if (!byte)
		{
			kill(ft_atoi(*str), SIGUSR1);
			free(*str);
			free(str);
			str = NULL;
			return (MAIN_SUCCESS);
		}
		str = str_cappend(str, byte);
		byte = 0;
	}
	return (SUCCESS);
}

void	signal_handler(int sig)
{
	static char	msg;

	if (msg == 0)
		msg = handle_msg(sig);
	else
		msg = handle_feedback(sig);
}

int	server_run(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putnbr(pid);
	ft_putchar('\n');
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (LOOP)
		;
	return (SUCCESS);
}
