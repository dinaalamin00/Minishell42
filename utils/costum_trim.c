/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costum_trim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:53:58 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/01 15:54:04 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*costum_trim(char *s1, char c, int pos)
{
	char	*ptr;
	int		j;
	int		i;

	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] == c && s1[i])
		i++;
	while (s1[j] == c && (j > i))
		j--;
	j++;
	if (pos == 1)
		j = ft_strlen(s1);
	else if (pos == 2)
		i = 0;
	ptr = malloc((j - i + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1 + i, j - i + 1);
	free(s1);
	return (ptr);
}
