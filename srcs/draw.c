/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcargou <rcargou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 14:21:39 by rcargou           #+#    #+#             */
/*   Updated: 2015/05/03 19:45:29 by tvallee          ###   ########.fr       */
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
	float ratio;

	ratio = 1 / ((3.0f - (type - 3)) / 3);
	if (type == NO_BLOCK)
		define_color(a, b, c, 0, 0, 0);
	else if (type == BLOCK_MORTAL)
		define_color(a, b, c, 0, 0, 255);
	else if (type == BLOCK_IMMORTAL)
		define_color(a, b, c, 0.5, 0.5, 0.5);
	else
		define_color(a, b, c, ratio - 1, 0, 1.0f / ratio);
	if (type >= 6)
		define_color(a, b, c, 1 , 0, 0);
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
	glVertex3f(i * 2 / 20 - 0.9 + (i + 1) * 0.05,
		(j * 2 / 10 - 1 + (j + 1) * 0.025) * -1, 0);
	glVertex3f(i * 2 / 20 - 0.9 + (i + 1) * 0.05,
		(j * 2 / 10 - 1  + 0.08 + (j + 1) * 0.025) * -1, 0);
	glVertex3f(i * 2 / 20 - 0.9 + 0.1 + (i + 1) * 0.05,
		(j * 2 / 10 - 1 + 0.08 + (j + 1) * 0.025) * - 1, 0);
	glVertex3f(i * 2 / 20 - 0.9 + 0.1 + (i + 1) * 0.05,
		(j * 2 / 10 - 1 + (j + 1) * 0.025) * -1, 0);
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

static void draw_bar(t_env *e)
{
	double pos_x;
	double pos_y;

	glfwGetCursorPos(e->window, &pos_x, &pos_y);
	glBegin(GL_QUADS);
	glColor3f(1, 1, 0);
	pos_x  = (pos_x - WINX / 2) / (WINX / 2) - 0.15;
	if (pos_x > 0.7)
		pos_x = 0.7;
	else if (pos_x < -1)
		pos_x = -1;
	if (e->ball.tethered)
		pos_x = -0.25;
	glVertex3f(pos_x , -0.8, 0);
	glColor3f(1, 0, 0);
	glVertex3f(pos_x + 0.1, -0.8 - 0.07, 0);
	glColor3f(0, 0, 1);
	glVertex3f(pos_x + 0.2, -0.8 - 0.07, 0);
	glColor3f(0, 1, 0);
	glVertex3f(pos_x + 0.2 + 0.1, -0.8, 0);
	glEnd();
}

static void draw_ball(float i, float j)
{
	float degInRad;
	float radius;
	int e;

	radius = 0.01;
	glBegin(GL_LINE_STRIP);
	while (radius >= 0)
	{
		e = 0;
		while (e < 360)
		{
			glColor3f(0, 1 - (radius * 70), radius * 60);
			degInRad = e*3.14159/180;
			glVertex2f(i + cos(degInRad)*radius, j + sin(degInRad)*radius);
			e++;
		}
		radius -= 0.001;
	}
	glEnd();
}

void draw(t_env *e)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	draw_rectangle(0, 0, e);
	draw_bar(e);
	draw_ball(e->ball.pos_x, e->ball.pos_y);
	glfwSwapBuffers(e->window);
}
