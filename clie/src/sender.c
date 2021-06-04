#include "minitalk.h"

int	send_pid(int pid)
{
	pid_t	my_pid;
	char	*tmp;

	my_pid = getpid();
	tmp = ft_itoa(my_pid);
	if (send_message(pid, tmp) == ERROR)
	{
		free(tmp);
		return (ERROR);
	}
	free(tmp);
	return (SUCCESS);
}

int	send_character(char c, int pid)
{
	short	changer;

	changer = 128;
	while (changer)
	{
		if (c & changer)
		{
			if (kill(pid, SIGUSR2) == ERROR)
				return (ERROR);
		}
		else if (kill(pid, SIGUSR1) == ERROR)
			return (ERROR);
		changer *= 0.5;
		usleep(60);
	}
	return (SUCCESS);
}

int	send_message(int pid, char *msg)
{
	short	changer;

	while (*msg)
	{
		if (send_character(*msg, pid) == ERROR)
			return (ERROR);
		msg++;
	}
	changer = 0;
	while (changer++ < 8)
	{
		if (kill(pid, SIGUSR1) == ERROR)
			return (ERROR);
		usleep(60);
	}
	return (SUCCESS);
}
