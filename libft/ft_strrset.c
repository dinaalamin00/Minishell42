
#include "libft.h"

char	*ft_strrset(const char *s, char *set)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (ft_strchr(set, ((char *)s)[i]))
			return ((char *)s + i);
		i--;
	}
	return (0);
}