/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:45:51 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/01 13:31:12 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char *s1, char const *set)
{
	char	*ptr;
	int		j;
	int		i;

	i = 0;
	j = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[i]) && s1[i])
		i++;
	while (ft_strchr(set, s1[j]) && (j > i))
		j--;
	j++;
	ptr = malloc((j - i + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1 + i, j - i + 1);
	return (ptr);
}
