/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:53:20 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/18 09:27:06 by mafaisal         ###   ########.fr       */
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
		ft_exit(shell);
	else if (!ft_strncmp(lower_cmd, "pwd", 4))
		ft_pwd(shell);
	else if (!ft_strncmp(shell->command[0], "cd", 3))
		ft_cd(shell);
	else if (!ft_strncmp(lower_cmd, "echo", 5))
		ft_echo(shell);
	else if (!ft_strncmp(shell->command[0], "export", 3))
		ft_export(shell);
	else if (!ft_strncmp(lower_cmd, "env", 4))
		ft_env(shell, 0);
	else if (!ft_strncmp(shell->command[0], "unset", 6))
		ft_unset(shell);
	else if (get_param(shell->params, "PATH"))
		execute_external(shell, env);
	else
		command_error(shell, NULL, ": No such file or directory");
	(reset_fds(shell), free_shell(shell, 0, -1), free(lower_cmd));
}
