/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:53:20 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/08 17:20:19 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_command(t_mshell *shell, char **env)
{
	// if (!ft_strncmp(ft_str_tolower(shell->command[0]), "pwd", 4))
	// 	ft_pwd(shell, env);
	// else if (!ft_strncmp(shell->command[0], "cd", 3))
	// 	ft_cd(shell, env);
	if (!ft_strncmp(ft_str_tolower(shell->command[0]), "echo", 3))
		ft_echo(shell);
	else if (!ft_strncmp(shell->command[0], "export", 3))
		ft_export(shell);
	// else if (!ft_strncmp(shell->command[0], "unset", 3))
	// 	ft_unset(shell, env);
	// else
	// 	execute_external(shell, env);
}

