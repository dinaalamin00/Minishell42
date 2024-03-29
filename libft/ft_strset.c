/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:33:37 by diahmed           #+#    #+#             */
/*   Updated: 2024/03/29 12:27:11 by mafaisal         ###   ########.fr       */
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
