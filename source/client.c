/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 03:12:24 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/06/25 11:03:56 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_package;

void	status_package(int signal)
{
	if (signal == SIGUSR1)
		g_package = 1;
}

void	char_to_binary(int pid, int c)
{
	int			i;
	int			character;

	i = 0;
	character = c;
	while (i < 8)
	{
		if (g_package == 1)
		{
			if (character % 2 == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			character = character / 2;
			i++;
			g_package = 0;
		}
		signal(SIGUSR1, status_package);
		while (!g_package)
			pause();
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	g_package = 1;
	if (argc != 3)
	{
		ft_printf("invalid arguments\n");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	if (pid == 0)
		ft_printf("The PID number invalid\n");
	while (argv[2][i])
	{
		char_to_binary(pid, argv[2][i]);
		i++;
	}
	char_to_binary(pid, '\n');
	return (0);
}
