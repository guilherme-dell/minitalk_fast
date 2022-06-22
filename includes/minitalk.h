/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 03:04:47 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/06/22 07:31:46 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>

//COLORS
# define GREEN		"\033[0;32m"
# define RED		"\033[1;31m"
# define GREY		"\033[0;90m"
# define RESET		"\033[0m"
# define START		"\033[05;32m"


// PROTOTYPES
int	ft_atoi(const char *nptr);



#endif