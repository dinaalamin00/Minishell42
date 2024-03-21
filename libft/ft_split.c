/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 09:59:25 by diahmed           #+#    #+#             */
/*   Updated: 2024/03/10 13:32:00 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	wordcount(const char *s, char c)
{
	size_t	i;
	int		cnt;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			cnt++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (cnt);
}

char	**ft_free(char **ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		ptr[i] = NULL;
		i++;
	}
	free(ptr);
	ptr = NULL;
	return (ptr);
}

char	*ft_sub(const char *s, char c, int *i, int *j)
{
	char	*ptr;

	*j = *i;
	while (s[(*i)] != c && s[(*i)])
		(*i)++;
	ptr = ft_substr(s, *j, (*i) - (*j));
	if (!ptr)
		return (NULL);
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**ptr;

	ptr = malloc ((wordcount(s, c) + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	i = 0;
	k = 0;
	while (s[i] != '\0' )
	{
		if (s[i] != c)
		{
			ptr[k] = ft_sub(s, c, &i, &j);
			if (!ptr[k])
				return (ft_free(ptr));
			k++;
		}
		else
			i++;
	}
	ptr[k] = NULL;
	return (ptr);
}
