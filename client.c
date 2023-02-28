/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:22:16 by hguillau          #+#    #+#             */
/*   Updated: 2023/02/28 17:44:38 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error()
{
	ft_putstr("not a valid PID");
	ft_putchar('\n');
	exit(1);
}

int	ft_isnum(char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (pid[i] < 48 || pid[i] > 57)
			return (1);
		i++;
	}
	return (0);
}

void	ft_to_send(int pid, char *msg, int len_msg)
{
	int	i;
	int	bit;

	i = 0;
	while (i <= len_msg)
	{
		bit = 0;
		while (bit < 7)
		{
			if (!((msg[i] >> bit) & 1))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(300);
			bit++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
		return (-1);
	if (ft_isnum(av[1]) == 1 || ft_atoi(av[1]) <= 0)
		ft_error();
	ft_to_send(ft_atoi(av[1]), av[2], ft_strlen(av[2]));
	system("leaks client >&2");
	return (0);
}
