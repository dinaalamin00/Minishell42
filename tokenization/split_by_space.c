/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:26:39 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/19 15:14:47 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**split_token(t_mshell *shell, char **array, char *string)
{
	int		i;
	char	**splitted;

	splitted = ft_split(string, 32);
	if (!splitted)
		return (NULL);
	i = 0;
	while (splitted[i])
	{
		array = append_to_array(shell, array, ft_strdup(splitted[i]));
		if (!array)
			break ;
		i++;
	}
	ft_free(splitted);
	return (array);
}

bool	split_by_space(t_mshell *shell)
{
	char	**new_tokens;
	int		i;

	i = 0;
	new_tokens = malloc (1 * sizeof (char *));
	if (!new_tokens)
		return (malloc_error(shell, 0, -1), FAILURE);
	new_tokens[0] = NULL;
	while (shell->tokens && shell->tokens[i])
	{
		if (!ft_strset(shell->tokens[i], "\"\'"))
			new_tokens = split_token(shell, new_tokens, shell->tokens[i]);
		else
			new_tokens = append_to_array(shell, new_tokens,
					ft_strdup(shell->tokens[i]));
		if (!new_tokens)
			return (malloc_error(shell, 0, -1), FAILURE);
		i++;
	}
	ft_free(shell->tokens);
	shell->tokens = new_tokens;
	return (SUCCESS);
}
