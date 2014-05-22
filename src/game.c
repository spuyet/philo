/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbacoux <mbacoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 18:44:15 by mbacoux           #+#    #+#             */
/*   Updated: 2014/05/09 18:44:16 by mbacoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <unistd.h>
#include "philo.h"

static void	ft_wait(t_prgm *prgm)
{
	XEvent	event;
	int		sec;

	while (XCheckWindowEvent(prgm->x, prgm->win,
							ExposureMask | KeyPressMask, &event))
		;
	sec = (int)time(NULL);
	while (1)
	{
		if (XCheckWindowEvent(prgm->x, prgm->win,
							ExposureMask | KeyPressMask, &event))
		{
			if (event.type == KeyPress)
				break ;
			else
				ft_render(prgm);
		}
		if ((int)time(NULL) != sec)
		{
			sec = (int)time(NULL);
			ft_render(prgm);
		}
		usleep(1);
	}
}

static void	ft_pause(t_prgm *prgm)
{
	int		sec;
	XEvent	event;

	sec = (int)time(NULL);
	while (sec == (int)time(NULL))
	{
		if (XCheckWindowEvent(prgm->x, prgm->win, ExposureMask, &event))
			ft_render(prgm);
		usleep(1);
	}
}

static int	ft_philo_alive(t_prgm *prgm)
{
	int	i;
	int	life;

	i = 0;
	while (i < PHILO_NUM)
	{
		pthread_mutex_lock(prgm->philo_mutex + i);
		life = prgm->philo[i].life;
		pthread_mutex_unlock(prgm->philo_mutex + i);
		if (life < 1)
			return (i);
		i++;
	}
	return (-1);
}

void		ft_game(t_prgm *prgm)
{
	size_t	sec;
	int		philo;

	sec = 0;
	prgm->end = 0;
	philo = -1;
	ft_render(prgm);
	while (!prgm->end)
	{
		if ((philo = ft_philo_alive(prgm)) != -1)
			prgm->end = END_DEATH;
		if (sec == TIMEOUT)
			prgm->end = END_TIMEOUT;
		ft_render(prgm);
		ft_pause(prgm);
		sec++;
	}
	prgm->running = 0;
	if (prgm->end == END_TIMEOUT)
		ft_putstr("Now, it is time... To DAAAAAAAANCE!!!\n");
	else
		ft_putstr("A philosopher is dead...\n");
	ft_wait(prgm);
	ft_exit(prgm);
}
