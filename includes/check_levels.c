/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_levels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 02:25:38 by tvallee           #+#    #+#             */
/*   Updated: 2015/05/02 02:33:46 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arkanoid.h"

int	check_levels(int ac, char **av, t_env *e)
{
	DIR		*dir;

	if (ac != 0)
	{
		temp = ft_strjoin(av[0], "/levels", 0);
		if (!(dir = opendir(temp)))
			return (0);
		if (!readdir(dir))
		{
			closedir(dir);
			return (0);
		}
		return (1);
	}
}
