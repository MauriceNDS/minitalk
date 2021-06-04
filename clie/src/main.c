#include "minitalk.h"

int	error_check(int argc, char *argv[])
{
	char	*tmp;

	if (argc != 3)
		return (ERROR);
	tmp = ft_itoa(ft_atoi(argv[1]));
	if (!ft_str_equals(argv[1], tmp) || argv[1][0] == '-' || argv[1][0] == '0')
	{
		free(tmp);
		return (ERROR);
	}
	free(tmp);
	return (SUCCESS);
}

void	feedback(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_putendl("Roger that!");
		exit(MAIN_SUCCESS);
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	signal(SIGUSR1, feedback);
	if (error_check(argc, argv) == ERROR)
	{
		ft_putendl("Error");
		return (MAIN_ERROR);
	}
	pid = ft_atoi(argv[1]);
	if (send_message(pid, argv[2]) == ERROR)
	{
		ft_putendl("Error");
		return (MAIN_ERROR);
	}
	if (send_pid(pid) == ERROR)
	{
		ft_putendl("Error");
		return (MAIN_ERROR);
	}
	pause();
	return (MAIN_SUCCESS);
}
