/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arkanoid.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 23:24:56 by tvallee           #+#    #+#             */
/*   Updated: 2015/05/02 09:02:29 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARKANOID
# define FT_ARKANOID

# include <sys/types.h>
# include <dirent.h>
# include "glfw3.h"
# include "libft.h"

# define G_PAUSED e->state == 2
# define G_RUNNING e->state == 1
# define G_MENU e->state == 0
# define G_OVER e->state == 3

typedef struct			s_lvl
{
	int					**lvl;
	struct s_lvl		*next;
}						t_lvl;

typedef struct			s_env
{
	GLFWwindow			*window;
	int					list_pos;
	int					state;
	double				pos_bar;
	t_lvl				*lvl_list;
}						t_env;

int						check_levels(int ac, char **av, t_env *e);
void					init_env(t_env *e);
void					init_hooks(t_env *e);

void					ft_menu(t_env *e, int callback);
void					ft_running(t_env *e);
void					ft_paused(t_env *e);
void					ft_gameover(t_env *e);

void					ft_exit(t_env *e);

void					key_callback(GLFWwindow* window, int key, int scancode,
							int action, int mods);

#endif
