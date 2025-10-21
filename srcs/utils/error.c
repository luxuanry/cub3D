#include "../../includes/cub3d.h"

int error_msg(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	if (msg)
	{
		ft_putstr_fd(msg, 2);
		ft_putstr_fd("\n", 2);
	}
	return (0);
}


int error_msg_prefix(char *prefix, char *msg)
{
	ft_putstr_fd("Error\n", 2);
	if (prefix)
		ft_putstr_fd(prefix, 2);
	if (msg)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(msg, 2);
	}
	ft_putstr_fd("\n", 2);
	return (0);
}

void exit_error(char *msg)
{
	error_msg(msg);
	exit(1);
}