#ifndef MINITALK_H
# define MINITALK_H

/******** INCLUDES ***********************************************************/

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

/******** DEFINES ************************************************************/

# define MAIN_SUCCESS   0
# define MAIN_ERROR     1
# define SUCCESS        1
# define FAILURE        0
# define ERROR          -1
# define LOOP           1

/******** PROTOTYPES *********************************************************/

// utility
ssize_t	ft_putnbr(long n);
ssize_t	ft_putstr(char *s);
ssize_t	ft_putchar(char c);
size_t	ft_strlen(const char *s);

// server
int		server_run(void);

// client
int		send_pid(int pid);
int		send_message(int pid, char *msg);

/*****************************************************************************/

#endif