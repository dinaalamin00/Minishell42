/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:33:37 by diahmed           #+#    #+#             */
/*   Updated: 2024/03/22 15:34:14 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* works like ft_strchr but with a set of characters */
char	*ft_strset(char *str, char *set)
{
	int	i;

	i = 0;
	if (!str || !set)
		return (NULL);
	while (str[i])
	{
		if (ft_strchr(set, str[i]))
			return (str + i);
		i++;
	}
	return (NULL);
}
