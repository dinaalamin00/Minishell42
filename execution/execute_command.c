/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:53:20 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/30 13:14:10 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_command(t_mshell *shell, char **env)
{
	char	*lower_cmd;

	lower_cmd = ft_str_tolower(ft_strdup(shell->command[0]));
	if (!lower_cmd)
		lower_cmd = shell->command[0];
	if (!ft_strncmp(shell->command[0], "exit", 5))
		shell->exit_code = ft_exit(shell);
	else if (!ft_strncmp(lower_cmd, "pwd", 4))
		shell->exit_code = ft_pwd(shell);
	else if (!ft_strncmp(shell->command[0], "cd", 3))
		shell->exit_code = ft_cd(shell);
	else if (!ft_strncmp(lower_cmd, "echo", 5))
		shell->exit_code = ft_echo(shell);
	else if (!ft_strncmp(shell->command[0], "export", 7))
		shell->exit_code = ft_export(shell);
	else if (!ft_strncmp(lower_cmd, "env", 4))
		shell->exit_code = ft_env(shell, 0);
	else if (!ft_strncmp(shell->command[0], "unset", 6))
		shell->exit_code = ft_unset(shell);
	else
	{
		(free(lower_cmd), lower_cmd = NULL);
		execute_external(shell, env);
	}
	(reset_fds(shell), free_shell(shell, 0, -1), free(lower_cmd));
}
