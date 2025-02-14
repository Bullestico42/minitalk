/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 08:53:42 by apiscopo          #+#    #+#             */
/*   Updated: 2025/01/22 21:17:03 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minitalk.h"

unsigned char	g_data = 0;

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int	bit_count;

	(void)info;
	(void)context;
	if (signum == SIGUSR2)
		g_data |= 1 << (7 - bit_count);
	bit_count++;
	if (bit_count == 8)
	{
		ft_printf("%c", g_data);
		g_data = 0;
		bit_count = 0;
	}
}

int	main(void)
{
	int					pid;
	sigset_t			mask;
	struct sigaction	sa;

	sigemptyset(&mask);
	pid = getpid();
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_mask = mask;
	ft_printf("PID = [%i]\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
