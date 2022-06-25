/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 03:04:47 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/06/25 12:17:03 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "ft_printf.h"

//COLORS
# define GREEN		"\033[0;32m"
# define RED		"\033[1;31m"
# define YELLOW		"\033[1;33m"
# define RESET		"\033[0m"
# define START		"\033[05;32m"

// PROTOTYPES
int	ft_atoi(const char *nptr);

#endif