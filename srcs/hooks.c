/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 05:37:41 by tvallee           #+#    #+#             */
/*   Updated: 2015/05/02 09:07:10 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arkanoid.h"

void	ft_up(t_env *e)
{
	if (e)
		return;
	else
		return;
}

void	ft_down(t_env *e)
{
	if (e)
		return ;
	else
		return;
}

void	ft_right(t_env *e)
{
	if (G_RUNNING)
	{
		e->pos_bar = (e->pos_bar < 0.92) ? e->pos_bar + 0.08 : 1;
		draw(e);
	}
}

void	ft_left(t_env *e)
{
	if (G_RUNNING)
	{
		e->pos_bar = (e->pos_bar > -0.92) ? e->pos_bar - 0.08 : -1;
		draw(e);
	}
}

void	key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	else if (key == GLFW_KEY_UP && (action == GLFW_PRESS ||
				action == GLFW_REPEAT))
		ft_up(ft_singleton(NULL));
	else if (key == GLFW_KEY_DOWN && (action == GLFW_PRESS ||
				action == GLFW_REPEAT))
		ft_down(ft_singleton(NULL));
	else if (key == GLFW_KEY_LEFT && (action == GLFW_PRESS ||
				action == GLFW_REPEAT))
		ft_left(ft_singleton(NULL));
	else if (key == GLFW_KEY_RIGHT && (action == GLFW_PRESS ||
				action == GLFW_REPEAT))
		ft_right(ft_singleton(NULL));
	else if (key == GLFW_KEY_ENTER && (action == GLFW_PRESS ||
				action == GLFW_REPEAT))
		ft_enter(ft_singleton(NULL));
	else
		ft_putnbr(key);
	ft_putchar(10);
	if (scancode && mods)
		mods = scancode;
}
