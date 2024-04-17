/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:24:28 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/17 19:00:40 by mafaisal         ###   ########.fr       */
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
	if (!new_string)
	{
		ft_putendl_fd("Malloc error! Free up some space", 2);
		free_shell(shell, 0, -1);
		return (NULL);
	}
	new_array = malloc ((array_len(array) + 2) * sizeof(char *));
	if (!new_array)
	{
		ft_putendl_fd("Malloc error! Free up some space", 2);
		free_shell(shell, 0, -1);
		return (NULL);
	}
	while (array[i])
	{
		new_array[i] = ft_strdup(array[i]);
		if (!new_array[i])
		{
			ft_putendl_fd("Malloc error! Free up some space", 2);
			ft_free(new_array);
			free_shell(shell, 0, -1);
			return (NULL);
		}
		i++;
	}
	new_array[i] = new_string;
	i++;
	new_array[i] = NULL;
	ft_free(array);
	return (new_array);
}
