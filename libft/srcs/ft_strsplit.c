/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:51:18 by tvallee           #+#    #+#             */
/*   Updated: 2014/12/30 08:29:06 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countstr(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			count++;
			i++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	t_delim	str;
	char	**r;
	size_t	nb;
	int		k;

	if (!s)
		return (NULL);
	nb = ft_countstr(s, c);
	r = malloc(sizeof(char *) * (nb + 1));
	str.i = 0;
	k = 0;
	while ((size_t)k < nb)
	{
		while (s[str.i] == c)
			str.i++;
		str.j = str.i;
		while (s[str.j] && s[str.j] != c)
			str.j++;
		r[k] = ft_strsub(s, str.i, str.j - str.i);
		k++;
		str.i = str.j + 1;
	}
	r[k] = NULL;
	return (r);
}
