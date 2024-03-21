/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:34:06 by diahmed           #+#    #+#             */
/*   Updated: 2023/11/07 14:53:37 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(dest) >= dstsize)
		return (ft_strlen(src) + dstsize);
	if (dstsize && (dstsize > ft_strlen(dest)))
	{
		while (dest[i])
			i++;
		while (((i + j) < dstsize - 1) && src[j])
		{
			dest[i + j] = src[j];
			j++;
		}
		dest[i + j] = '\0';
	}
	while (src[j])
		j++;
	return (i + j);
}
