/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:22:08 by hguillau          #+#    #+#             */
/*   Updated: 2023/03/03 09:53:28 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_strchar(char *s1, char c)
{
	char	*res;
	int		i;
	int		j;

	i = ft_strlen(s1);
	j = 0;
	res = malloc((i + 3) * sizeof (char));
	if (!res)
		return (NULL);
	if (s1)
	{
		while (j <= i)
		{
			res[j] = s1[j];
			j++;
		}
	}
	res[i] = c;
	res[i + 1] = 0;
	free(s1);
	return (res);
}

void	ft_to_print(int signal)
{
	static char	*s1;
	static int	i;
	static int	bit;
	static int	j;

	i += ((signal & 1) << bit);
	bit++;
	if (bit == 7)
	{
		printf("i = %d | ", i);
		s1 = ft_strchar(s1, i);
		if (i == 0)
		{
			ft_putstr(s1);
			ft_putchar('\n');
			free(s1);
			s1 = NULL;
		}
		i = 0;
		bit = 0;
		j++;
	}
}

int	main(void)
{
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
	{
		signal(SIGUSR1, ft_to_print);
		signal(SIGUSR2, ft_to_print);
		sleep(1);
	}
	return (0);
}
