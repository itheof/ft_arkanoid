/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 23:23:54 by tvallee           #+#    #+#             */
/*   Updated: 2015/05/03 20:22:24 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arkanoid.h"

void	rule_them_all(t_env *e)
{
	if (G_RUNNING)
		ft_running(e);
	change_title(e);
}

t_env	*ft_singleton(t_env *e)
{
	static t_env *save = NULL;

	if (e)
		save = e;
	return (save);
}

void	ft_start_game(t_env *e)
{
	e->score = 0;
	e->state = 1;
	e->ball.pos_x = -0.1;
	e->ball.pos_y = -0.8;
	e->ball.tethered = 1;
}

int		main(int ac, char **av)
{
	t_env	e;

	ft_singleton(&e);
	e.lvl_list = NULL;
	if (!check_levels(ac, av, &e) || !glfwInit())
		return (-1);
	e.maxscore = 0;
	e.lvl = 0;
	e.window = glfwCreateWindow(WINX, WINY, "Arkanoid", NULL, NULL);
	if (!e.window)
	{
		glfwTerminate();
		return (-1);
	}
	glfwMakeContextCurrent(e.window);
	init_hooks(&e);
	ft_start_game(&e);
	while (!glfwWindowShouldClose(e.window))
	{
		rule_them_all(&e);
		glfwPollEvents();
	}
	glfwTerminate();
	return (0);
}
