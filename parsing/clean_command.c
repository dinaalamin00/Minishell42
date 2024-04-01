/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:23:16 by mafaisal          #+#    #+#             */
/*   Updated: 2024/04/01 16:20:28 by diahmed          ###   ########.fr       */
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
			shell->tokens[i] = custom_trim(shell->tokens[i], ' ', 0);
			if (is_quote(shell->tokens[i][0]))
				shell->tokens[i] = custom_trim(shell->tokens[i], shell->tokens[i][0], 0);
			shell->command = append_to_array(shell->command,
					ft_strdup(shell->tokens[i]));
		}
		i++;
	}
}
