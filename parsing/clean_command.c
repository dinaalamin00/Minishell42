/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:23:16 by mafaisal          #+#    #+#             */
/*   Updated: 2024/04/01 13:46:25 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	clean_command(t_mshell *shell)
{
	int		i;
	char	*temp;

	shell->command = malloc(sizeof(char *));
	shell->command[0] = NULL;
	i = 0;
	while (shell->tokens[i])
	{
		if (shell->tokens[i][0])
		{
			temp = shell->tokens[i];
			shell->tokens[i] = ft_strtrim(shell->tokens[i], " \t");
			free(temp);
			if (is_quote(shell->tokens[i][0]))
			{
				temp = shell->tokens[i];
				shell->tokens[i] = ft_strtrim(shell->tokens[i], "\"");
				free(temp);
			}
			shell->command = append_to_array(shell->command,
					ft_strdup(shell->tokens[i]));
		}
		i++;
	}
}
