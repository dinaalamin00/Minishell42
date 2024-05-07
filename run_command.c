/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:33:14 by mafaisal          #+#    #+#             */
/*   Updated: 2024/05/05 12:02:57 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wait_child(t_mshell *shell, int i)
{
	pid_t	child_pid;
	int		j;

	j = 0;
	while (j < i)
	{
		child_pid = waitpid(-1, &shell->exit_code, 0);
		if (child_pid > 0)
			shell->exit_code = WEXITSTATUS(shell->exit_code);
		j++;
	}
}

void	run_one(t_mshell *shell)
{
	int	exit_value;

	shell->user_input = shell->pipe_command[shell->pipe_i];
	exit_value = tokenizer(shell);
	if (exit_value == EXIT_FAILURE)
	{
		shell->exit_code = exit_value;
		return ;
	}
	exit_value = parser(shell);
	if (exit_value == EXIT_FAILURE)
	{
		shell->exit_code = exit_value;
		return ;
	}
	executor(shell);
}

void	run_pipe(t_mshell *shell)
{
	int		pfd[2];
	pid_t	pid;

	while (shell->pipe_command[shell->pipe_i])
	{
		if (pipe(pfd) < 0)
			perror("pipe creation: ");
		pid = fork();
		if (pid < 0)
		{
			perror(NULL);
			break ;
		}
		else if (pid == 0)
			pipe_child(shell, pfd);
		else
			pipe_parent(shell, pfd);
	}
	wait_child(shell, shell->pipe_i);
}

void	run_command(t_mshell *shell)
{
	int	exit_value;

	check_signal(shell);
	exit_value = pipe_check(shell);
	if (exit_value == EXIT_FAILURE)
	{
		shell->exit_code = exit_value;
		if (shell->user_input)
			(free(shell->user_input), shell->user_input = NULL);
		return ;
	}
	shell->pipe_i = 0;
	if (!shell->pipe_command[1])
		run_one(shell);
	else
		run_pipe(shell);
	free_shell(shell, 0, -1);
	reset_fds(shell);
}
