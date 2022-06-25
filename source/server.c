/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 03:21:46 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/06/25 13:41:07 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	binary_to_char(int signal, siginfo_t *info, void *context)
{
	static int		base = 1;
	static char		character = 0;
	int				pid;

	if (signal == SIGUSR1)
		character += base;
	base *= 2;
	if (base == 256)
	{
		ft_printf("%c", character);
		base = 1;
		character = 0;
	}
	context = (void *)context;
	pid = info->si_pid;
	usleep(200);
	kill(pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf(START"[SERVER STARTED]\n"RESET);
	ft_printf("SERVER PID:\033[0;33m %d\033[0m\n", getpid());
	sa.sa_sigaction = binary_to_char;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, 0) < 0 || sigaction(SIGUSR2, &sa, 0) < 0)
		return (1);
	while (1)
		pause();
	return (0);
}
