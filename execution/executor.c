/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:59:59 by mafaisal          #+#    #+#             */
/*   Updated: 2024/04/25 07:52:18 by mafaisal         ###   ########.fr       */
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
	if (shell->command && shell->command[0])
		execute_command(shell, env);
	return (reset_fds(shell), 0);
}
