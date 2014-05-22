/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbacoux <mbacoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 18:42:50 by mbacoux           #+#    #+#             */
/*   Updated: 2014/05/09 18:42:51 by mbacoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "philo.h"

size_t	ft_strlen(char *str)
{
	size_t		len;

	len = 0;
	while (*str && str++)
		len++;
	return (len);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_fatal_error(char *error)
{
	ft_putstr("error: ");
	ft_putstr(error);
	write(1, "\n", 1);
	exit(EXIT_FAILURE);
}
