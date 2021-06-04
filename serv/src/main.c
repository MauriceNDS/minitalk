#include "minitalk.h"

int	main(int argc, char *argv[])
{
	(void)argv;
	if (argc != 1)
	{
		ft_putendl("Error");
		return (MAIN_ERROR);
	}
	server_run();
	return (MAIN_SUCCESS);
}
