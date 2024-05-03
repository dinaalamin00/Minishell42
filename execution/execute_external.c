/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_external.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:02:27 by diahmed           #+#    #+#             */
/*   Updated: 2024/05/03 15:31:09 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	is_accessible(t_mshell *shell, char **path, char **env)
{
	char	*exec;
	int		i;

	i = -1;
	while (path && path[++i])
	{
		exec = ft_str_join(path[i], "/");
		if (exec)
			exec = ft_strjoin(exec, shell->command[0]);
		else
			(free(exec), malloc_error(shell, 1, 1));
		if (exec)
		{
			if (!access(exec, F_OK | X_OK))
			{
				if (execve(exec, shell->command, env) < 0)
					(free(exec), perror("execve"), free_shell(shell, 1, 1));
			}
			free(exec);
		}
		else
			(free(exec), malloc_error(shell, 1, 1));
	}
}

char	**get_path(t_mshell *shell)
{
	t_param	*path;

	path = get_param(shell->params, "PATH");
	if (path && path->value)
		return (ft_split((path->value), ':'));
	else
	{
		shell->exit_code = command_error(shell,
				NULL, ": No such file or directory", 127);
		free_shell(shell, 1, shell->exit_code);
	}
	return (NULL);
}

static void	exec_extern_child(t_mshell *shell, char **env)
{
	char	**path;

	if (!access(shell->command[0], F_OK | X_OK))
		execve(shell->command[0], shell->command, env);
	path = get_path(shell);
	if (!path || !path[0])
	{
		command_error(shell, NULL, ": No such file or directory", 127);
		free_shell(shell, 1, 127);
	}
	is_accessible(shell, path, env);
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
	if (pid == 0)
		exec_extern_child(shell, env);
	else
	{
		if (signal(SIGINT, SIG_IGN) == SIG_ERR)
			perror("SIGINT Error");
		if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
			perror("SIGQUIT Error");
		waitpid(pid, &shell->exit_code, 0);
		check_signal(shell);
	}
	return (0);
}
