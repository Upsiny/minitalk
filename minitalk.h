/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:28:06 by hguillau          #+#    #+#             */
/*   Updated: 2023/03/03 10:46:29 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

// SERVEUR
char	*ft_strjoin(char const *s1, char const *s2);

// CLIENT
void	ft_to_send(int pid, char *msg, int len_msg);

// UTILS
int		ft_strlen(char *str);
int		ft_atoi(char *str);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	ft_putchar(int c);

#endif
