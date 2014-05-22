/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbacoux <mbacoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 18:44:46 by mbacoux           #+#    #+#             */
/*   Updated: 2014/05/09 18:44:48 by mbacoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"

void		ft_put_state(t_philo *philo, int state)
{
	philo->state = state;
	if (state == EAT)
		philo->timer = EAT_T;
	else if (state == THINK)
		philo->timer = THINK_T;
	else if (state == REST)
		philo->timer = REST_T;
}

void		ft_state_change(int index, t_prgm *prgm, int state)
{
	if (state == EAT)
	{
		prgm->philo[index].life = MAX_LIFE;
		ft_put_state(prgm->philo + index, REST);
		pthread_mutex_unlock(prgm->wand + index);
		pthread_mutex_unlock(prgm->wand + ft_right(index));
	}
	else if (state == THINK)
	{
		if (pthread_mutex_trylock(prgm->wand + ft_right(index)) == 0)
			ft_put_state(prgm->philo + index, EAT);
	}
	else
	{
		if (prgm->philo[ft_left(index)].state == THINK
			|| prgm->philo[ft_right(index)].state == THINK
			|| pthread_mutex_trylock(prgm->wand + index))
			;
		else if (pthread_mutex_trylock(prgm->wand + ft_right(index)))
			ft_put_state(prgm->philo + index, THINK);
		else
			ft_put_state(prgm->philo + index, EAT);
	}
}

void		ft_live(int index, t_prgm *prgm)
{
	while (prgm->running)
	{
		pthread_mutex_lock(prgm->philo_mutex + index);
		if (prgm->philo[index].timer)
			prgm->philo[index].timer--;
		if (prgm->philo[index].timer == 0)
			ft_state_change(index, prgm, prgm->philo[index].state);
		if (prgm->philo[index].state != EAT)
			prgm->philo[index].life--;
		pthread_mutex_unlock(prgm->philo_mutex + index);
		usleep(1000000);
	}
}
