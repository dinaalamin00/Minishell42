/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:40:04 by diahmed           #+#    #+#             */
/*   Updated: 2023/11/10 12:31:15 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((i < n) && ((((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
		&& s1[i] && s2[i]))
		i++;
	if (i < n)
		return ((((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]));
	return (0);
}
