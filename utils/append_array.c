/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:24:28 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/19 13:14:34 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	array_len(char	**array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

char	**append_to_array(t_mshell *shell, char	**array, char *new_string)
{
	char	**new_array;
	int		i;

	i = 0;
	if (!new_string || !array)
		return (malloc_error(shell, 0, -1), free(new_string), NULL);
	new_array = malloc ((array_len(array) + 2) * sizeof(char *));
	if (!new_array)
		return (malloc_error(shell, 0, -1), free(new_string), NULL);
	while (array[i])
	{
		new_array[i] = ft_strdup(array[i]);
		if (!new_array[i])
		{
			ft_free(new_array);
			return (malloc_error(shell, 0, -1), free(new_string), NULL);
		}
		i++;
	}
	new_array[i] = new_string;
	i++;
	new_array[i] = NULL;
	ft_free(array);
	return (new_array);
}
