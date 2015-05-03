/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcargou <rcargou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:46:39 by rcargou           #+#    #+#             */
/*   Updated: 2015/05/03 23:13:45 by rcargou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arkanoid.h"

void		get_color(int type, float *a, float *b, float *c)
{
	float ratio;

	ratio = 1 / ((3.0f - (type - 3)) / 3);
	if (type == NO_BLOCK)
		define_color(a, b, c, 0, 0);
	else if (type == BLOCK_MORTAL)
		define_color(a, b, c, 0, 255);
	else if (type == BLOCK_IMMORTAL)
	{
		define_color(a, b, c, 0.5, 0.5);
		*b = 0.5;
	}
	else
		define_color(a, b, c, ratio - 1, 1.0f / ratio);
	if (type >= 6)
		define_color(a, b, c, 1, 0);
}

void			define_color(float *a, float *b, float *c, float va,
		float vc)
{
	*a = va;
	*b = 0;
	*c = vc;
}
