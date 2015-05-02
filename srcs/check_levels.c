/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_levels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 02:25:38 by tvallee           #+#    #+#             */
/*   Updated: 2015/05/02 15:51:07 by rcargou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arkanoid.h"

int	check_levels(int ac, char **av, t_env *e)
{
	DIR				*dir;
	struct dirent	*file;

	if (ac != 0)
	{
		e->lvl_dir = ft_strjoin(ft_strndup(av[0], ft_strlen(av[0]) -
						ft_strlen(ft_strrchr(av[0], '/'))), "/levels", 1);
		if (!(dir = opendir(e->lvl_dir)))
			return (0);
		if (!(file = readdir(dir)))
		{
			closedir(dir);
			return (0);
		}
		load_levels(e, dir, file);
		return (1);
	}
	return (0);
}
