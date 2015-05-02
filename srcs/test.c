/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 23:23:54 by tvallee           #+#    #+#             */
/*   Updated: 2015/05/02 03:06:32 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arkanoid.h"


int main(int ac, char **av)
{
	t_env	e;

	if (!check_levels(ac, av, &e))
		return (-1);
	init_env(&e);
	if (!glfwInit())
		return (-1);
	e.window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!e.window)
	{
		glfwTerminate();
		return (-1);
	}
	glfwMakeContextCurrent(e.window);
	init_hooks(&e);
	while (!glfwWindowShouldClose(e.window))
	{
		
		glfwSwapBuffers(e.window);
		glfwPollEvents();
	}
	glfwTerminate();
/*	ft_exit(&e);*/
	return 0;
}
