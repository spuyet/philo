/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbacoux <mbacoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 18:44:52 by mbacoux           #+#    #+#             */
/*   Updated: 2014/05/09 18:44:54 by mbacoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		ft_draw_wand(t_prgm *prgm, int i)
{
	float	a;

	a = 90.0f + i * (360 / PHILO_NUM);
	glColor3f(0.8f, 0.8f, 0.8f);
	glBegin(GL_LINES);
	if (prgm->philo[i].state == EAT || prgm->philo[i].state == THINK)
	{
		glVertex2f(130.0f * ft_cos(a) - 15.0f, 130.0f * ft_sin(a) + 10.0f);
		glVertex2f(130.0f * ft_cos(a) - 15.0f, 130.0f * ft_sin(a) - 10.0f);
	}
	if (prgm->philo[i].state == EAT)
	{
		glVertex2f(130.0f * ft_cos(a) + 15.0f, 130.0f * ft_sin(a) + 10.0f);
		glVertex2f(130.0f * ft_cos(a) + 15.0f, 130.0f * ft_sin(a) - 10.0f);
	}
	if (prgm->philo[i].state == REST && prgm->philo[ft_left(i)].state != EAT)
	{
		a -= 180 / PHILO_NUM;
		glVertex2f(90.0f * ft_cos(a), 90.0f * ft_sin(a));
		glVertex2f(70.0f * ft_cos(a), 70.0f * ft_sin(a));
	}
	glEnd();
}

void		ft_draw_life(t_philo *philo)
{
	float	lp;

	lp = (float)philo->life / (float)MAX_LIFE;
	if (lp < 0.0f)
		lp = 0.0f;
	if (lp > 0.5)
		glColor3f(1.5f - 3.0f * (lp - 0.5f), 1.0, 0.0f);
	else
		glColor3f(1.0f, lp, 0.0f);
	glBegin(GL_QUADS);
	glVertex2f(-20.0f, 28.0f);
	glVertex2f(-20.0f, 32.0f);
	glVertex2f(-20.0f + 40.0f * lp, 32.0f);
	glVertex2f(-20.0f + 40.0f * lp, 28.0f);
	glEnd();
}

static void	ft_draw_stuff(t_prgm *prgm, size_t i)
{
	glColor3f(1.0f, 1.0f, 1.0f);
	if (prgm->philo[i].life > 0)
	{
		glBegin(GL_TRIANGLES);
		glVertex2f(-9.0f, -5.0f);
		glVertex2f(9.0f, -5.0f);
		glVertex2f(0.0f, -15.0f);
		glEnd();
	}
	glPointSize(3.0f);
	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-5.0f, 2.5f);
	glVertex2f(5.0f, 2.5f);
	glEnd();
}

static void	ft_draw_philo(t_prgm *prgm)
{
	size_t	i;
	float	a;

	i = 0;
	glPushMatrix();
	while (i < PHILO_NUM)
	{
		glColor3f(1.0f, 0.76f, 0.67f);
		if (prgm->philo[i].life <= 0)
			glColor3f(1.0f, 1.0f, 1.0f);
		a = 90.0f + i * (360 / PHILO_NUM);
		glTranslatef(130.0f * ft_cos(a), 130.0f * ft_sin(a), 0.0f);
		gluDisk(prgm->philoq, 0.0, 10.0, 36, 1);
		ft_draw_stuff(prgm, i);
		pthread_mutex_lock(prgm->philo_mutex + i);
		ft_draw_life(prgm->philo + i);
		glLoadIdentity();
		glTranslatef(400.0f, 300.0f, 0.0f);
		ft_draw_wand(prgm, (int)i);
		pthread_mutex_unlock(prgm->philo_mutex + i);
		glPopMatrix();
		glPushMatrix();
		i++;
	}
	glPopMatrix();
}

void		ft_render(t_prgm *prgm)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(0.53f, 0.26f, 0.11f);
	glTranslatef(400.0f, 300.0f, 0.0f);
	gluDisk(prgm->table, 0.0, 100.0, 360, 1);
	if (prgm->end == END_TIMEOUT && time(NULL) % 2)
		glTranslatef(0.0f, 4.0f, 0.0f);
	ft_draw_philo(prgm);
	glFlush();
	glXSwapBuffers(prgm->x, prgm->win);
}
