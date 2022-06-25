/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 03:12:24 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/06/25 07:16:03 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
//SIGUSR1 1
//SIGUSR2 0
void	char_to_binary(int pid, char c)
{
	t_packge	packge;
	int			i;
	int			character;

	i = 0;
	character = c;
	while (i < 8)
	{
		if (character % 2 == 1)
			packge.bin[7 - i] = "1";
		else
			packge.bin[7 - i] = "0";
		character = character / 2;
		i++;
	}
	i = 0;
	while (*packge.bin[i] != '\0')
	{
		if (ft_atoi(packge.bin[i]) == 1)
		{
			kill(pid, SIGUSR1);
			usleep(2500);
		}
		else
		{
			kill(pid, SIGUSR2);
			usleep(2500);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
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

// kill -l EXIBTE TODOS OS SINAIS 'a'