/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 23:23:54 by tvallee           #+#    #+#             */
/*   Updated: 2015/05/02 17:10:53 by rcargou          ###   ########.fr       */
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

void	ft_print_levels(t_lvl *lvl)
{
	int i;
	int j;
	int	**tab;

	if (!lvl)
		return ;
	tab = lvl->lvl;
	i = 0;
	j = 0;
	ft_putchar(10);
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			ft_putnbr(tab[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar(10);
		i++;
	}
	ft_print_levels(lvl->next);
}

int main(int ac, char **av)
{
	t_env	e;

	ft_singleton(&e);
	e.lvl_list = NULL;
	if (!check_levels(ac, av, &e))
		return (-1);
	if (!glfwInit())
		return (-1);
	ft_print_levels(e.lvl_list);
	
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
		draw(&e);
		rule_them_all(&e);
		glfwSwapBuffers(e.window);
		glfwPollEvents();
	}
	glfwTerminate();

/*	ft_exit(&e);*/
	return 0;
}
