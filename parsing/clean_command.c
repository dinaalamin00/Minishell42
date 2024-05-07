/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:23:16 by mafaisal          #+#    #+#             */
/*   Updated: 2024/04/24 09:54:48 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	clean_command(t_mshell *shell)
{
	int		i;

	shell->command = malloc(sizeof(char *));
	if (!shell->command)
		return (malloc_error(shell, 0, -1), FAILURE);
	shell->command[0] = NULL;
	i = -1;
	while (shell->tokens[++i])
	{
		if (shell->tokens[i][0])
		{
			shell->tokens[i] = custom_trim(shell->tokens[i], ' ', 0);
			if (shell->tokens[i] && is_quote(shell->tokens[i][0]))
				shell->tokens[i] = custom_trim(shell->tokens[i],
						shell->tokens[i][0], 0);
			shell->command = append_to_array(shell, shell->command,
					ft_strdup(shell->tokens[i]));
			if (!shell->tokens[i] || !shell->command)
				return (malloc_error(shell, 0, -1), FAILURE);
		}
	}
	return (SUCCESS);
}
