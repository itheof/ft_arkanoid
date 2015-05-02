/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 23:23:54 by tvallee           #+#    #+#             */
/*   Updated: 2015/05/02 07:30:21 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arkanoid.h"

void	rule_them_all(t_env *e)
{
	if (G_MENU)
		ft_menu(e, 0);
	else if (G_RUNNING)
		ft_running(e);/*
	else if (G_PAUSED)
		ft_paused(e);
	else if (G_OVER)
		ft_gameover(e);*/
}

t_env	*ft_singleton(t_env *e)
{
	static t_env *save = NULL;

	if (e)
		save = e;
	return (save);
}

int main(int ac, char **av)
{
	t_env	e;

	if (!check_levels(ac, av, &e))
		return (-1);
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
	e.state = 1;
	e.list_pos = 0;
	ft_singleton(&e);
	while (!glfwWindowShouldClose(e.window))
	{
		rule_them_all(&e);
		glfwSwapBuffers(e.window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}
