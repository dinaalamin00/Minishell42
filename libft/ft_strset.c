/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:33:37 by diahmed           #+#    #+#             */
/*   Updated: 2024/03/28 11:13:37 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strset(char *str, char *set)
// {
// 	int	i;

// 	i = 0;
// 	if (!str || !set)
// 		return (NULL);
// 	while (ft_strchr(set, str[i]) && (i > 0 && str[i] == str[i - 1]))
// 		i++;
// 	while (str[i])
// 	{
// 		if (ft_strchr(set, str[i]))
// 			return (str + i);
// 		i++;
// 	}
// 	return (NULL);
// }

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
