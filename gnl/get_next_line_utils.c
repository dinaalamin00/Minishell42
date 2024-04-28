/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:01:34 by mafaisal          #+#    #+#             */
/*   Updated: 2024/04/05 10:33:12 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*allocated;
	size_t	i;

	if (count > (2147483647 / size))
		return (NULL);
	allocated = malloc(count * size);
	if (!allocated)
		return (NULL);
	i = 0;
	while (i < (count * size))
	{
		*(allocated + i) = '\0';
		i++;
	}
	return (allocated);
}

size_t	ft_len_to_char(const char *str, char c)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	if (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == ((char)c))
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

void	ft_copy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return ;
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*ft_str_join(char const *s1, char const *s2)
{
	char	*new;
	size_t	len1;
	size_t	len2;
	size_t	newlen;
	size_t	i;

	if (!s1 && !s2)
		return (NULL);
	len1 = ft_len_to_char((char *)s1, '\0');
	len2 = ft_len_to_char((char *)s2, '\0');
	newlen = len1 + len2;
	new = malloc((newlen + 1) * sizeof(char));
	if (!new)
		return (NULL);
	if (s1)
		ft_copy(new, s1, len1 + 1);
	i = 0;
	while (i < len2)
	{
		new[len1 + i] = s2[i];
		i++;
	}
	new[newlen] = '\0';
	return (new);
}
