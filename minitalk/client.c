/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:20:49 by mvolpi            #+#    #+#             */
/*   Updated: 2022/03/24 11:40:43 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"

void	handler(int signo, siginfo_t *siginfo, void *unused)
{
	(void)unused;
	(void)siginfo;
	(void)signo;
}

void	bit_by_bit(int pid, int bit)
{
	int	counter;

	counter = 0;
	while (counter <= 7)
	{
		if ((bit >> counter) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_putstr_fd("Error signal\n", 1);
				exit (0);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_putstr_fd("Error signal\n", 1);
				exit (0);
			}
		}
		counter++;
		usleep(100);
	}
}

void	send_bit(int pid, char *msg)
{
	struct sigaction	act;
	siginfo_t			siginfo;
	int					i;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &handler;
	sigemptyset(&act.sa_mask);
	sigaction(SIGUSR1, &act, 0);
	siginfo.si_pid = pid;
	i = 0;
	while (msg[i] != '\0')
		bit_by_bit(pid, msg[i++]);
	ft_putstr_fd("message received\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		send_bit(ft_atoi(argv[1]), argv[2]);
	else
	{
		return (write(0, "3 arguments must be passed: \
			[0]/client [1]pid [2]message", 59));
		exit (0);
	}
	return (0);
}
