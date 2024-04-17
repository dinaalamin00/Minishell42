/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:23:16 by mafaisal          #+#    #+#             */
/*   Updated: 2024/04/17 18:58:44 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	clean_command(t_mshell *shell)
{
	int		i;
	char	*temp;

	shell->command = malloc(sizeof(char *));
	if (!shell->command)
		return ;
	shell->command[0] = NULL;
	i = 0;
	while (shell->tokens[i])
	{
		if (shell->tokens[i][0])
		{
			shell->tokens[i] = custom_trim(shell->tokens[i], ' ', 0);
			if (!shell->tokens[i])
			{
				ft_putendl_fd("Malloc error! Free up some space", 2);
				free_shell(shell, 0, -1);
				return ;
			}
			if (is_quote(shell->tokens[i][0]))
				shell->tokens[i] = custom_trim(shell->tokens[i], shell->tokens[i][0], 0);
			if (!shell->tokens[i])
			{
				ft_putendl_fd("Malloc error! Free up some space", 2);
				free_shell(shell, 0, -1);
				return ;
			}
			shell->command = append_to_array(shell, shell->command,
					ft_strdup(shell->tokens[i]));
			if (!shell->command)
			{
				ft_putendl_fd("Malloc error! Free up some space", 2);
				free_shell(shell, 0, -1);
				return ;
			}
		}
		i++;
	}
}
