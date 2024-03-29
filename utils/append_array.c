/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:24:28 by diahmed           #+#    #+#             */
/*   Updated: 2024/03/28 14:34:52 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	array_len(char	**array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

char	**append_to_array(char	**array, char *new_string)
{
	char	**new_array;
	int		i;

	i = 0;
	new_array = malloc ((array_len(array) + 2) * sizeof(char *));
	if (!new_array)
		return (NULL);
	while (array[i])
	{
		new_array[i] = ft_strdup(array[i]);
		i++;
	}
	new_array[i] = new_string;
	i++;
	new_array[i] = NULL;
	ft_free(array);
	return (new_array);
}
