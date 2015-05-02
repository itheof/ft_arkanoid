/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcargou <rcargou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 14:21:39 by rcargou           #+#    #+#             */
/*   Updated: 2015/05/02 17:22:10 by rcargou          ###   ########.fr       */
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
		define_color(a, b, c, 0, 0, 0);
	else if (type == BLOCK_MORTAL)
		define_color(a, b, c, 0, 0, 255);
	else if (type == BLOCK_HP)
		define_color(a, b, c, 255.0f / (10 - (type - 2)), 0, 0);
	else
		define_color(a, b, c, 122, 122, 122);
}


static void draw_rectangle(float i, float j, t_env *e)
{
	float a;
	float b;
	float c;

	a = 255;
b = 0;
c = 0;
	if (j > 4)
		return ;
	get_color((e->lvl_list->lvl)[(int)j][(int)i], &a, &b, &c);
	glBegin(GL_QUADS);
	glColor3f(a, b, c);
	glVertex3f(i * 2 / 20 - 1 + (i + 1) * 0.05,
		j * 2 / 10 - 1 + (j + 1) * 0.025, 0);
	glVertex3f(i * 2 / 20 - 1 + 0.1 + (i + 1) * 0.05,
		j * 2 / 10 - 1 + (j + 1) * 0.025, 0);
	glVertex3f(i * 2 / 20 - 1 + (i + 1) * 0.05,
		j * 2 / 10 - 1  + 0.07 + (j + 1) * 0.025, 0);
	glVertex3f(i * 2 / 20 - 1 + 0.1 + (i + 1) * 0.05,
		j * 2 / 10 - 1 + 0.07 + (j + 1) * 0.025, 0);
	glEnd();
	if (i > 9)
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
	glfwSwapBuffers(e->window);
}
