/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:04:46 by diahmed           #+#    #+#             */
/*   Updated: 2024/03/25 18:11:20 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
static int	line_len(char *str, char *set)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strchr(set, str[i]))
			return (i);
		i++;
	}
	return (i);
}

char	*ft_strccpy(char *src, char *set)
{
	char	*dest;
	int		i;

	i = 0;
	if (!src)
		return (NULL);
	dest = malloc ((line_len(src, set) + 1) * sizeof(char));
	while (src[i])
	{
		if (!ft_strchr(set, src[i]))
		{
			dest[i] = src[i];
			i++;
		}
		else
			break ;
	}
	dest[i] = '\0';
	return (dest);
}
