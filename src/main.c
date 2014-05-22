/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbacoux <mbacoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 18:44:22 by mbacoux           #+#    #+#             */
/*   Updated: 2014/05/09 18:44:23 by mbacoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int			main(void)
{
	t_prgm	prgm;
	size_t	i;

	ft_zero(&prgm, sizeof(t_prgm));
	i = 0;
	while (i < PHILO_NUM)
	{
		prgm.philo[i].life = MAX_LIFE;
		pthread_mutex_init(prgm.philo_mutex + i, NULL);
		pthread_mutex_init(prgm.wand + i, NULL);
		i++;
	}
	prgm.running = 1;
	ft_init_window(&prgm);
	ft_run(&prgm);
	return (0);
}
