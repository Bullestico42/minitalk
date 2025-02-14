/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 08:53:44 by apiscopo          #+#    #+#             */
/*   Updated: 2025/01/22 21:23:30 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minitalk.h"

void	send_signal(int pid, const char *str)
{
	int	i;

	while (*str)
	{
		i = 0;
		while (i < 8)
		{
			if ((*str >> (7 - i)) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(70);
			i++;
		}
		str++;
	}
	ft_printf("The message is sent\n");
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc > 3 || argc < 3)
		return (0);
	pid = ft_atoi(argv[1]);
	send_signal(pid, argv[2]);
	return (0);
}
