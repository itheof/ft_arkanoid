/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arkanoid.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 23:24:56 by tvallee           #+#    #+#             */
/*   Updated: 2015/05/02 02:56:08 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARKANOID
# define FT_ARKANOID

# include "glfw3.h"
# include "libft.h"

typedef struct			s_env
{
	GLFWwindow			*window;
	char				*lvl_dir;
}						t_env;

#endif
