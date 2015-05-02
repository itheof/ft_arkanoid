/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_running.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 05:37:03 by tvallee           #+#    #+#             */
/*   Updated: 2015/05/02 06:04:52 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arkanoid.h"

void	ft_running(t_env *e)
{
	if (!e->ball.tethered)
	{
/*		if (can_move(e->ball))
		{*/
			e->ball.pos_x += e->ball.s_x;
			e->ball.pos_y += e->ball.s_y;
/*		}
		else
			collision(e);*/
	}
	draw(e);
}
