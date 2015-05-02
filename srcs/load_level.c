/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 07:24:55 by tvallee           #+#    #+#             */
/*   Updated: 2015/05/02 08:49:32 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arkanoid.h"

void	clean_levels(t_env *e)
{
	//Should free the whole list of levels;
}

int		*ft_toline(char **tab)
{
	int		*res;
	int		i;

	i = 0;
	res = ft_memalloc(sizeof(int) * (ft_tablen(tab) + 1));
	while (tab[i])
	{
		res[i] = ft_atoi(tab[i]);
		free(tab[i++]);
	}
	free(tab);
	res[i] = 0;
	return (res);
}

int		**get_tab(int fd, t_list *temp)
{
	char	*str;
	t_list	*list;
	int		**tab;
	int		i;

	list = NULL;
	while (get_next_line(&str, fd) == 1)
		ft_lstpushback(&list, ft_lstnewcopy(ft_strsplit(str, ' '), 0));
	tab = ft_memalloc(sizeof(int *) * (ft_lstlen(list) + 1));
	i = 0;
	while (list)
	{
		tab[i++] = ft_toline(list->data);
		temp = list;
		list = list->next;
		free(temp);
	}
	return (tab);
}

t_lvl	*ft_parse_lvl(struct dirent *file, DIR *dir)
{
	t_lvl	*new;
	int		fd;

	if (file)
	{
		if ((fd = open(file->d_name, O_RDONLY)) < 1)
		{
			ft_putendl("Error while loading levels");
			ft_exit(ft_singleton(NULL));
		}
		new = malloc(sizeof(*new));
/*    ADD HERE LEVEL PARAMETERS    */
		new->lvl = get_tab(fd, NULL);
		close(fd);
		new->next = ft_parse_lvl(readdir(dir), dir);
		return (new);
	}
	else
		return (NULL);
}

void	load_levels(t_env *e, DIR *dir, struct dirent *dirent)
{z
	if (e->lvl_list)
		clean_levels(t_env *e);
	e->lvl_list = ft_parse_lvl(dirent, dir);
	closedir(dir);
	ft_putendl("Levels loaded successfully ! =)");
}
