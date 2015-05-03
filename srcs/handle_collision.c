/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcargou <rcargou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 07:00:28 by rcargou           #+#    #+#             */
/*   Updated: 2015/05/03 16:31:41 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arkanoid.h"

void handle_bricks(t_env *e, t_collision col)
{
	int type;

	type = (e->lvl_list->lvl[col.tabIndexY][col.tabIndexX]);
	if (type == NO_BLOCK)
		return ;
	if (type == BLOCK_MORTAL)
		(e->lvl_list->lvl[col.tabIndexY][col.tabIndexX]) = NO_BLOCK;
	if (type > 3)
	{
		(e->lvl_list->lvl[col.tabIndexY][col.tabIndexX]) -= 1;
		if (type == 4)
			(e->lvl_list->lvl[col.tabIndexY][col.tabIndexX]) = NO_BLOCK;
	}
	if (col.ship_hit > 0.1 && col.ship_hit < 0.9)
		e->ball.s_y *= -1;
	else
		e->ball.s_x *= -1;
}

void handle_wall(t_env *e, t_collision col)
{
	if(col.wallSide == 1)
		e->ball.s_x = ABS(e->ball.s_x);
	if (col.wallSide == 2)
		e->ball.s_y = -ABS(e->ball.s_y);
	if (col.wallSide == 3)
		e->ball.s_x = -ABS(e->ball.s_x);
	if (!col.wallSide)
		ft_start_game(e);
}

void handle_raq(t_env *env, t_collision col)
{
	env->ball.s_x *= 0;
	if (col.ship_hit >= 0.5)
		env->ball.s_x += fabs(col.ship_hit - 0.5) / 20;
	else 
		env->ball.s_x -= fabs(col.ship_hit - 0.5) / 20;
	env->ball.s_y = fabs(env->ball.s_y);
}

void handle_collision(t_env *e, t_collision col)
{
	if (col.which == 0)
		handle_bricks(e, col);
	if (col.which == 1)
		handle_wall(e, col);
	if (col.which == 2)
		handle_raq(e, col);
}
