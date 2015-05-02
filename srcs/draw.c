/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcargou <rcargou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 14:21:39 by rcargou           #+#    #+#             */
/*   Updated: 2015/05/02 15:48:51 by rcargou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arkanoid.h"

void define_color(float *a, float *b, float *c, float va, float vb, float vc)
{
	*a = va;
	*b = vb;
	*c = vc;
}

static void get_color(int type, float *a, float *b, float *c)
{
	if (type == NO_BLOCK)
	{
		define_color(a, b, c, 0, 0, 0);
	}
	else
		define_color(a, b, c, 255, 0, 0);
}


static void draw_rectangle(float i, float j, t_env *e)
{
	float a;
	float b;
	float c;

	if (i >= 9 && j >= 4)
		return ;
	get_color((e->lvl_list->lvl)[(int)i][(int)j], &a, &b, &c);
    glBegin(GL_QUADS);
	glColor3f(a, b, c);
	glVertex3f(i * 2 / 20 - 1 + (i + 1) * 0.05, j * 2 / 10 - 1 + (j + 1) * 0.025, 0);
	glVertex3f(i * 2 / 20 - 1 + (i + 1) * 0.05, j * 2 / 10 - 1 + (j + 1) * 0.025, 0);
	glVertex3f(i * 2 / 20 - 1 + (i + 1) * 0.05, j * 2 / 10 - 1 + (j + 1) * 0.025, 0);
	glVertex3f(i * 2 / 20 - 1 + (i + 1) * 0.05, j * 2 / 10 - 1 + (j + 1) * 0.025, 0);
	glEnd();
	if (i == 9)
	{
		i = 0;
		j++;
	}
	else
		i++;
	draw_rectangle(i, j, e);
}

void draw(t_env *e)
{
	glLoadIdentity();
	draw_rectangle(0, 0, e);
}
