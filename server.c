/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 03:21:46 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/06/22 07:55:52 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_receive(int signal)
{
	printf("Received signal = %d\n", signal);
}

int	main(void)
{
	int pid;
	int x;
	x = 0;

	pid = getpid();
	printf(START"[SERVER STARTED]\n"RESET);
	printf("SERVER PID: %d\n", pid);

	signal(10, signal_receive);
	signal(12, signal_receive);
	while (1)
	{
		printf("%d\n", x);
		x++;
		sleep(1);
	}

	return 0;
}