/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 03:12:24 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/06/22 07:54:35 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_sig(int pid)
{
	kill(pid, SIGUSR1);
	usleep(700);
}

int	main(int argc, char **argv)
{
	int	pid;
	int i;
	i = 0;
	if (argc != 3)
	{
		printf("invalid arguments\n");
		exit(EXIT_FAILURE);
	}

	pid = ft_atoi(argv[1]);

	while (argv[2][i])
	{
		printf("%c", argv[2][i]);
		send_sig(pid);
		i++;
	}
	return (0);
}

// kill -l EXIBTE TODOS OS SINAIS