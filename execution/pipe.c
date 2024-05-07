/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 11:01:16 by diahmed           #+#    #+#             */
/*   Updated: 2024/05/05 11:06:30 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	pipe_child(t_mshell *shell, int pfd[2])
{
	close(pfd[0]);
	if (shell->pipe_command[shell->pipe_i + 1])
	{
		if (dup2(pfd[1], STDOUT_FILENO) < 0)
		{
			perror("STDOUT duplication:");
			exit(1);
		}
	}
	close(pfd[1]);
	run_one(shell);
	free_shell(shell, 1, shell->exit_code);
}

void	pipe_parent(t_mshell *shell, int pfd[2])
{
	if (signal(SIGINT, SIG_IGN) == SIG_ERR)
		perror("SIGQUIT Error");
	reset_fds(shell);
	close(pfd[1]);
	shell->exit_code = WEXITSTATUS(shell->exit_code);
	shell->pipe_i++;
	if (dup2(pfd[0], STDIN_FILENO) < 0)
	{
		perror("STDIN duplication:");
		return ;
	}
	close(pfd[0]);
}
