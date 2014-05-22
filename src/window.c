/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbacoux <mbacoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 18:45:03 by mbacoux           #+#    #+#             */
/*   Updated: 2014/05/09 18:45:05 by mbacoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static GLint		g_attr[] = {
	GLX_RGBA,
	GLX_DEPTH_SIZE,
	24,
	GLX_DOUBLEBUFFER,
	None
};

void				ft_init_props(t_prgm *prgm)
{
	XSizeHints		*win_size;
	Atom			win_delete;

	win_delete = XInternAtom(prgm->x, "WM_DELETE_WINDOW", False);
	XSetWMProtocols(prgm->x, prgm->win, &win_delete, 1);
	win_size = XAllocSizeHints();
	win_size->flags = PMaxSize | PMinSize;
	win_size->min_width = 800;
	win_size->min_height = 600;
	win_size->max_width = 800;
	win_size->max_height = 600;
	XSetWMNormalHints(prgm->x, prgm->win, win_size);
	XFree(win_size);
}

void				ft_init_window(t_prgm *prgm)
{
	prgm->x = XOpenDisplay(NULL);
	prgm->root = DefaultRootWindow(prgm->x);
	prgm->vi = glXChooseVisual(prgm->x, 0, g_attr);
	prgm->cmap = XCreateColormap(prgm->x, prgm->root, prgm->vi->visual,
								AllocNone);
	prgm->swa.colormap = prgm->cmap;
	prgm->swa.event_mask = ExposureMask | KeyPressMask;
	prgm->win = XCreateWindow(prgm->x, prgm->root, 0, 0, 800, 600, 0,
							prgm->vi->depth, InputOutput, prgm->vi->visual,
							CWColormap | CWEventMask, &(prgm->swa));
	ft_init_props(prgm);
	XMapWindow(prgm->x, prgm->win);
	XStoreName(prgm->x, prgm->win, "Les Voisins Philosophes");
	prgm->glc = glXCreateContext(prgm->x, prgm->vi, NULL, GL_TRUE);
	glXMakeCurrent(prgm->x, prgm->win, prgm->glc);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glOrtho(0.0, 800.0, 0.0, 600.0, -1.0, 0.0);
	glMatrixMode(GL_MODELVIEW);
	prgm->table = gluNewQuadric();
	prgm->philoq = gluNewQuadric();
}
