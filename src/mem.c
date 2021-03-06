/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbacoux <mbacoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 18:44:36 by mbacoux           #+#    #+#             */
/*   Updated: 2014/05/09 18:44:37 by mbacoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void		ft_zero(void *ptr, size_t size)
{
	size_t	i;
	char	*dat;

	i = 0;
	dat = (char *)ptr;
	while (i < size)
		dat[i++] = 0;
}
