/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:33:37 by diahmed           #+#    #+#             */
/*   Updated: 2024/03/14 11:41:14 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strset(char *str, char *set)
{
	int	i;

	i = 0;
	if (!str || !set)
		return (NULL);
	i++;
	while (ft_strchr(set, str[i]) && str[i] == str[i - 1])
		i++;
	while (str[i])
	{
		if (ft_strchr(set, str[i]))
			return (str + i);
		i++;
	}
	return (NULL);
}
