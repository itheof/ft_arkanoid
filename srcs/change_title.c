/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_title.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 17:45:15 by tvallee           #+#    #+#             */
/*   Updated: 2015/05/03 17:56:44 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arkanoid.h"

static void	render_score_int(char buffer[1024], int value)
{
	char*tmp;

	tmp = ft_itoa(value);
	ft_strcat(buffer, tmp);
	free(tmp);
}

static int ft_lvllen(t_lvl *list)
{
	int i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

void	change_title(t_env *e)
{
	char buffer[1024];

	if (e->score > e->maxscore)
		e->maxscore = e->score;
	ft_strcpy(buffer, "Arkanoid: Level: ");
	render_score_int(buffer, e->lvl + 1);
	ft_strcat(buffer, "/");
	render_score_int(buffer, ft_lvllen(e->lvl_list));
	ft_strcat(buffer, "   |   Score: current: ");
	render_score_int(buffer, e->score);
	ft_strcat(buffer, " max: ");
	render_score_int(buffer, e->maxscore);
	glfwSetWindowTitle(e->window, buffer);
}
