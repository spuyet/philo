/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbacoux <mbacoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 18:42:57 by mbacoux           #+#    #+#             */
/*   Updated: 2014/05/09 18:42:59 by mbacoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void			ft_exit(t_prgm *prgm)
{
	size_t		i;

	i = 0;
	while (i < PHILO_NUM)
		pthread_join(prgm->thread[i++], NULL);
	glXMakeCurrent(prgm->x, None, NULL);
	glXDestroyContext(prgm->x, prgm->glc);
	XCloseDisplay(prgm->x);
}
