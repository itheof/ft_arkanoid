/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arkanoid.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 23:24:56 by tvallee           #+#    #+#             */
/*   Updated: 2015/05/02 03:42:11 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARKANOID
# define FT_ARKANOID

# include <sys/types.h>
# include <dirent.h>
# include "glfw3.h"
# include "libft.h"

typedef struct			s_env
{
	GLFWwindow			*window;
	char				*lvl_dir;
}						t_env;

int                     check_levels(int ac, char **av, t_env *e);
void                    init_env(t_env *e);
void                    init_hooks(t_env *e);

#endif
