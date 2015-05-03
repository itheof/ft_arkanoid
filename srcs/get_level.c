/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_level.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 20:11:59 by tvallee           #+#    #+#             */
/*   Updated: 2015/05/03 20:44:18 by rcargou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arkanoid.h"

t_lvl	*get_level(t_env *e, int lvl)
{
	t_lvl *list;

	list = e->lvl_list;
	while (lvl)
	{
		list = list->next;
		lvl--;
	}
	return (list);
}
