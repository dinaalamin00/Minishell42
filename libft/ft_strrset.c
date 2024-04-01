/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:51:49 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/01 15:51:55 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
