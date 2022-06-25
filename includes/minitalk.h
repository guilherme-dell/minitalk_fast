/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 03:04:47 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/06/25 03:53:39 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include "ft_printf.h"

//COLORS
# define GREEN		"\033[0;32m"
# define RED		"\033[1;31m"
# define RESET		"\033[0m"
# define START		"\033[05;32m"


typedef struct s_packge
{
	char *bin[8];
}	t_packge;


// PROTOTYPES
int	ft_atoi(const char *nptr);

#endif