/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcargou <rcargou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 07:00:28 by rcargou           #+#    #+#             */
/*   Updated: 2015/05/03 22:39:03 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arkanoid.h"

void handle_bricks(t_env *e, t_collision col)
{
	int		type;
	t_lvl	*l;

	l = get_level(e, e->lvl);
	type = (l->lvl[col.tabindexy][col.tabindexx]);
	if (type == NO_BLOCK)
		return ;
	if (type == BLOCK_MORTAL)
	{
		(l->lvl[col.tabindexy][col.tabindexx]) = NO_BLOCK;
		e->score += 10;
	}
	if (type >= 3)
	{
		(l->lvl[col.tabindexy][col.tabindexx]) -= 1;
		e->score += 10;
		if (type == 3)
			(l->lvl[col.tabindexy][col.tabindexx]) = NO_BLOCK;
	}
	if (col.ship_hit > 0.1 && col.ship_hit < 0.9)
		e->ball.s_y *= -1;
	else
		e->ball.s_x *= -1;
}

void handle_wall(t_env *e, t_collision col)
{
	if (col.wallside == 1)
		e->ball.s_x = ABS(e->ball.s_x);
	if (col.wallside == 2)
		e->ball.s_y = -ABS(e->ball.s_y);
	if (col.wallside == 3)
		e->ball.s_x = -ABS(e->ball.s_x);
	if (!col.wallside)
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
