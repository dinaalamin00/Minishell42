/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:59:59 by mafaisal          #+#    #+#             */
/*   Updated: 2024/05/01 17:55:06 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	executor(t_mshell *shell, char **env)
{
	int	file_error;

	shell->orig_stdin = dup(STDIN_FILENO);
	shell->orig_stdout = dup(STDOUT_FILENO);
	file_error = 0;
	if (!open_dup(shell))
		return (reset_fds(shell), 1);
	printf("exit code out : %d\n", shell->exit_code);
	if (shell->command && shell->command[0]
		&& shell->here_flag != 1)
		execute_command(shell, env);
	return (reset_fds(shell), 0);
}
