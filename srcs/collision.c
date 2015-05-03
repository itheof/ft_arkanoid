/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcargou <rcargou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 20:23:55 by rcargou           #+#    #+#             */
/*   Updated: 2015/05/03 19:19:42 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arkanoid.h"

int collision_bricks(t_collision *collision, t_env *e)
{
	double i;
	double j;
	double posbrickx;
	double posbricky;

	i = -1;
	while (++i <= 10 && (j = -1))
	{
		while (++j < 5)
		{
			posbrickx = i * 2 / 20 - 0.9 + (i + 1) * 0.05;
			posbricky = -1 * (j * 2 / 10 - 0.9 + (j + 1) * 0.025);
			if (e->ball.pos_x + e->ball.s_x >= posbrickx && e->ball.pos_x + 
					e->ball.s_x <= posbrickx + 0.1 && e->ball.pos_y + 
					e->ball.s_y >= posbricky && e->ball.pos_y + e->ball.s_y <=
					posbricky + 0.12)
			{
				collision->which = 0;
				collision->tabIndexX = i;
				collision->tabIndexY = j;
				collision->ship_hit = (e->ball.pos_x - posbrickx) / 0.1;
				return (1);
			}
		}
	}
	return (0);
}

int collision_raq(t_collision *collision, t_env *e)
{
	double pos_x;
	double pos_y;

	glfwGetCursorPos(e->window, &pos_x, &pos_y);
	pos_x = (pos_x - WINX / 2) / (WINX / 2) - 0.15;
	if (pos_x > 0.7)
		pos_x = 0.7;
	else if (pos_x < -1)
		pos_x = -1;
	pos_y = 0.8;
	if (e->ball.pos_x > pos_x && e->ball.pos_x < pos_x + 0.3
		&& pos_y * -1 >= e->ball.pos_y && pos_y * -1 <= e->ball.pos_y + 0.1)
	{
		collision->which = 2;
		collision->ship_hit = (e->ball.pos_x - pos_x) / 0.3;
		return (1);
	}
	return (collision_bricks(collision, e));
}

int collision(t_collision *collision, t_env *e)
{
	if (e->ball.pos_x >= 1)
	{
		collision->which = 1;
		collision->wallSide = 3;
	}
	else if (e->ball.pos_x <= -1)
	{
		collision->which = 1;
		collision->wallSide = 1;
	}
	else if (e->ball.pos_y >= 1)
	{
		collision->which = 1;
		collision->wallSide = 2;
	}
	else if (e->ball.pos_y <= -1)
	{
		collision->which = 1;
		collision->wallSide = 0;
	}
	else if (collision_raq(collision, e))
		;
	else
		return (0);
	return (1);
}
