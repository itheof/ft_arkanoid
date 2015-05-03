/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_running.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 05:37:03 by tvallee           #+#    #+#             */
/*   Updated: 2015/05/03 08:20:22 by rcargou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arkanoid.h"

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
	draw(e);
}
