#include "libft.h"

char	*ft_strndup(char const *str, size_t n)
{
	int		i;
	char	*new;


	i = 0;
	new = malloc(sizeof(*new) * (n + 1));
	while (n-- && *str)
	{
		new[i++] = *str++;
	}
	new[i] = 0;
	return (new);
}
