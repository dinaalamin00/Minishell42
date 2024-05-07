/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_external.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:02:27 by diahmed           #+#    #+#             */
/*   Updated: 2024/05/05 13:59:36 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**get_path(t_mshell *shell, char **env)
{
	t_param	*path;

	path = get_param(shell->params, "PATH");
	if (path && path->value)
		return (ft_split((path->value), ':'));
	else
	{
		ft_free(env);
		shell->exit_code = command_error(shell,
				NULL, ": No such file or directory", 127);
		free_shell(shell, 1, shell->exit_code);
	}
	return (NULL);
}

static void	exec_extern_child(t_mshell *shell, char **env)
{
	char	**path;

	is_accessible_absolute(shell, env);
	path = get_path(shell, env);
	if (!path || !path[0])
	{
		ft_free(env);
		command_error(shell, NULL, ": No such file or directory", 127);
		(ft_free(path), free_shell(shell, 1, 127));
	}
	is_accessible_relative(shell, path, env);
	ft_free(env);
	command_error(shell, NULL, ": command not found", 127);
	(ft_free(path), free_shell(shell, 1, 127));
}

static void	exec_extern_parent(t_mshell *shell)
{
	if (WIFSIGNALED(shell->exit_code))
	{
		if (WTERMSIG(shell->exit_code) == SIGINT)
			shell->exit_code = 130;
		else if (WTERMSIG(shell->exit_code) == SIGQUIT)
			shell->exit_code = 131;
	}
	else
		shell->exit_code = WEXITSTATUS(shell->exit_code);
}

int	execute_external(t_mshell *shell, char **env)
{
	pid_t	pid;

	if (signal(SIGINT, &exec_handler) == SIG_ERR)
		perror("SIGINT Error");
	if (signal(SIGQUIT, &exec_handler) == SIG_ERR)
		perror("SIGQUIT Error");
	pid = fork();
	if (pid < 0)
		return (perror(NULL), 1);
	if (pid == 0)
		exec_extern_child(shell, env);
	else
	{
		if (signal(SIGINT, SIG_IGN) == SIG_ERR)
			perror("SIGINT Error");
		if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
			perror("SIGQUIT Error");
		waitpid(pid, &shell->exit_code, 0);
		ft_free(env);
		exec_extern_parent(shell);
		check_signal(shell);
	}
	return (0);
}
