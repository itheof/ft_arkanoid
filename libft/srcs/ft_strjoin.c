/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:09:05 by tvallee           #+#    #+#             */
/*   Updated: 2014/12/30 08:49:45 by tvallee          ###   ########.fr       */
/*   ## nb specifes input strings to free, 3 = both, 0 = none                 */
/* ************************************************************************** */

#include "libft.h"

static int	free_appropriately(char *s1, char *s2, int nb)
{
	if (nb == 1)
		free(s1);
	if (nb == 2)
		free(s2);
	if (nb == 3)
	{
		free(s1);
		free(s2);
	}
	return (0);
}

char		*ft_strjoin(char const *s1, char const *s2, int nb)
{
	char	*r;
	int		i;
	int		j;

	if (s1 && s2)
	{
		r = ft_memalloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
		if (r && (j = 0) == 0)
		{
			i = 0;
			while (s1[i])
			{
				r[i] = s1[i];
				i++;
			}
			while (s2[j])
			{
				r[i + j] = s2[j];
				j++;
			}
			r[i + j] = 0;
		}
		free_appropriately((char *)s1, (char *)s2, nb);
	}
	return (r);
}
