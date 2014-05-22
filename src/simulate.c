/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbacoux <mbacoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 18:44:57 by mbacoux           #+#    #+#             */
/*   Updated: 2014/05/09 18:44:58 by mbacoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

static void		*ft_live_wrapper(void *data)
{
	t_philo_def	*def;
	t_prgm		*prgm;
	int			index;

	def = (t_philo_def *)data;
	index = def->index;
	prgm = def->prgm;
	def->index = -1;
	ft_live(index, prgm);
	return (NULL);
}

void			ft_run(t_prgm *prgm)
{
	int			i;
	t_philo_def	def;

	i = 0;
	def.prgm = prgm;
	while (i < PHILO_NUM)
	{
		def.index = i;
		pthread_create(&(prgm->thread[i]), NULL, ft_live_wrapper, &def);
		while (def.index != -1)
			;
		i++;
	}
	ft_game(prgm);
}
