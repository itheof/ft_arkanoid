/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_running.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 05:37:03 by tvallee           #+#    #+#             */
/*   Updated: 2015/05/03 20:19:52 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arkanoid.h"

static int		level_completed(t_env *e)
{
	t_lvl	*lvl;
	int		i;
	int		j;

	lvl = get_level(e, e->lvl);
	i = 0;
	j = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 11)
		{
			if (lvl->lvl[i][j] == BLOCK_MORTAL || lvl->lvl[i][j] == BLOCK_HP)
				return (0);
		}
	}
	return (1);
}

void	ft_running(t_env *e)
{
	t_collision c;

	if (!e->ball.tethered)
	{
		if (collision(&c, e))
			handle_collision(e, c);
		e->ball.pos_x += e->ball.s_x;
		e->ball.pos_y += e->ball.s_y;
	}
	if (level_completed(e))
	{
		e->score += 200;
		e->lvl++;
		e->state = 1;
		e->ball.pos_x = - 0.1;
		e->ball.pos_y = - 0.8;
		e->ball.tethered = 1;
	}
	if (!get_level(e, e->lvl))
		ft_exit(e);
	draw(e);
}
