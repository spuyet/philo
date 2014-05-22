/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neighboor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbacoux <mbacoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 18:44:41 by mbacoux           #+#    #+#             */
/*   Updated: 2014/05/09 18:44:43 by mbacoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int			ft_left(int index)
{
	if (index > 0)
		return (index - 1);
	return (PHILO_NUM - 1);
}

int			ft_right(int index)
{
	if (index < PHILO_NUM - 1)
		return (index + 1);
	return (0);
}
