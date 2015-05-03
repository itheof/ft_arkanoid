/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 07:24:55 by tvallee           #+#    #+#             */
/*   Updated: 2015/05/03 19:39:00 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arkanoid.h"

static int		*ft_toline(char **tab)
{
	int		*res;
	int		i;

	i = 0;
	res = ft_memalloc(sizeof(int) * (ft_tablen((void **)tab) + 1));
	while (tab[i])
	{
		res[i] = ft_atoi(tab[i]) > 0 ? ft_atoi(tab[i]) : 0;
		if (res[i] > 6)
			res[i] = 6;
		free(tab[i++]);
	}
	free(tab);
	res[i] = 0;
	return (res);
}

static int		**get_tab(int fd, t_list *temp)
{
	char	*str;
	t_list	*list;
	int		**tab;
	int		i;

	list = NULL;
	while (get_next_line(fd, &str) == 1)
		ft_lstpushback(&list, ft_lstnewcopy(ft_strsplit(str, ' '), 0));
	tab = ft_memalloc(sizeof(int *) * (ft_lstlen(list) + 1));
	i = 0;
	while (list)
	{
		tab[i++] = ft_toline(list->content);
		temp = list;
		list = list->next;
		free(temp);
	}
	tab[i] = 0;
	return (tab);
}

static t_lvl	*ft_parse_lvl(struct dirent *file, DIR *dir)
{
	t_lvl	*new;
	int		fd;
	char	*temp;

	if (file)
	{
		if (file->d_name[0] != '.')
		{
			temp = ft_strjoin(ft_singleton(NULL)->lvl_dir, ft_strjoin(
						"/", file->d_name, 0), 2);
			if ((fd = open(temp, O_RDONLY)) < 1)
				free(temp);
			free(temp);
			new = malloc(sizeof(*new));
			new->lvl = get_tab(fd, NULL);
			close(fd);
			new->next = ft_parse_lvl(readdir(dir), dir);
		}
		else
			new = ft_parse_lvl(readdir(dir), dir);
		return (new);
	}
	else
		return (NULL);
}

void			clean_levels(t_env *e)
{

}

void			load_levels(t_env *e, DIR *dir, struct dirent *dirent)
{
	if (e->lvl_list)
		clean_levels(e);
	e->lvl_list = ft_parse_lvl(dirent, dir);
	closedir(dir);
	ft_putendl("Levels loaded successfully ! =)");
}
