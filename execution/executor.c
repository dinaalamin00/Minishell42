/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:59:59 by mafaisal          #+#    #+#             */
/*   Updated: 2024/04/19 15:18:15 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	executor(t_mshell *shell, char **env)
{
	shell->orig_stdin = dup(STDIN_FILENO);
	shell->orig_stdout = dup(STDOUT_FILENO);
	open_dup(shell);
	if (shell->command && shell->command[0])
		execute_command(shell, env);
	return (0);
}
