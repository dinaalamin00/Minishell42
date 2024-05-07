/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:53:20 by diahmed           #+#    #+#             */
/*   Updated: 2024/05/05 13:37:07 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_command(t_mshell *shell)
{
	if (!ft_strncmp(shell->command[0], "exit", 5))
		shell->exit_code = ft_exit(shell);
	else if (!ft_strncmp(shell->command[0], "pwd", 4))
		shell->exit_code = ft_pwd(shell);
	else if (!ft_strncmp(shell->command[0], "cd", 3))
		shell->exit_code = ft_cd(shell);
	else if (!ft_strncmp(shell->command[0], "echo", 5))
		shell->exit_code = ft_echo(shell);
	else if (!ft_strncmp(shell->command[0], "export", 7))
		shell->exit_code = ft_export(shell);
	else if (!ft_strncmp(shell->command[0], "env", 4))
		shell->exit_code = ft_env(shell, 0);
	else if (!ft_strncmp(shell->command[0], "unset", 6))
		shell->exit_code = ft_unset(shell);
	else
		execute_external(shell, list_to_env(shell));
	free_shell(shell, 0, -1);
}
