/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbacoux <mbacoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 18:42:39 by mbacoux           #+#    #+#             */
/*   Updated: 2014/05/09 18:42:45 by mbacoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <X11/Xlib.h>
# include <X11/Xatom.h>
# include <GL/glx.h>
# include <GL/glu.h>
# include <pthread.h>
# include <stddef.h>

# define MAX_LIFE			20
# define EAT_T				5
# define REST_T				7
# define THINK_T			5
# define PHILO_NUM			7
# define TIMEOUT			60
# define REST				0
# define THINK				1
# define EAT				2

# define END_TIMEOUT		1
# define END_DEATH			2

typedef struct				s_philo
{
	int						state;
	int						life;
	int						timer;
}							t_philo;

typedef struct				s_prgm
{
	t_philo					philo[PHILO_NUM];
	pthread_mutex_t			philo_mutex[PHILO_NUM];
	pthread_mutex_t			wand[PHILO_NUM];
	pthread_t				thread[PHILO_NUM];
	int						running;
	int						end;
	Display					*x;
	Window					root;
	Window					win;
	XVisualInfo				*vi;
	Colormap				cmap;
	XSetWindowAttributes	swa;
	GLXContext				glc;
	GLUquadric				*table;
	GLUquadric				*philoq;
}							t_prgm;

typedef struct				s_philo_def
{
	int						index;
	t_prgm					*prgm;
}							t_philo_def;

/*
** error.c
*/

size_t						ft_strlen(char *str);
void						ft_putstr(char *str);
void						ft_fatal_error(char *error);

/*
** exit.c
*/

void						ft_exit(t_prgm *prgm);

/*
** game.c
*/

void						ft_game(t_prgm *prgm);

/*
** math.c
*/

float						ft_cos(float angle);
float						ft_sin(float angle);

/*
** mem.c
*/

void						ft_zero(void *ptr, size_t size);

/*
** neighboor.c
*/

int							ft_left(int index);
int							ft_right(int index);

/*
** philo.c
*/

void						ft_live(int index, t_prgm *prgm);

/*
** render.c
*/

void						ft_render(t_prgm *prgm);

/*
** simulate.c
*/

void						ft_run(t_prgm *prgm);

/*
** window.c
*/

void						ft_init_window(t_prgm *prgm);

#endif
