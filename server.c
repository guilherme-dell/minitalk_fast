/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 03:21:46 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/06/25 07:14:37 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	binary_to_char(int signal)
{
	static int	binary[8];
	static int	i = 0;
	static int	base = 128;
	static int	total = 0;
	char		character;

	if (signal == SIGUSR1)
	{
		total = total + (base * 1);
		base = base / 2;
		i++;
	}
	else
	{
		base = base / 2;
		i++;
	}
	if (i == 8)
	{
		character = total;
		ft_printf("%c", character);
		total = 0;
		base = 128;
		i = 0;
	}
	usleep(2000);
}

int	main(void)
{
	int	pid;
	int	x;

	x = 0;
	pid = getpid();
	ft_printf(START"[SERVER STARTED]\n"RESET);
	ft_printf("SERVER PID: %d\n", pid);
	signal(SIGUSR1, binary_to_char);
	signal(SIGUSR2, binary_to_char);
	while (1)
		pause();
	return (0);
}
