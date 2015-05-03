/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 05:37:41 by tvallee           #+#    #+#             */
/*   Updated: 2015/05/03 18:27:09 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arkanoid.h"

void	ft_space(t_env *e)
{
	if (G_RUNNING && e->ball.tethered)
	{
		e->ball.s_x = 0;
		e->ball.tethered = 0;
		e->ball.s_y = DEFAULT_SPEED;
	}
}

void	key_callback(GLFWwindow *window, int key, int scancode, int action,
		int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	else if (key == GLFW_KEY_SPACE && (action == GLFW_PRESS ||
				action == GLFW_REPEAT))
		ft_space(ft_singleton(NULL));
	if (scancode && mods)
		mods = scancode;
}
