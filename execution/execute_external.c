/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_external.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:02:27 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/23 12:55:00 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	is_accessible(t_mshell *shell, char **path, char **env)
{
	char	*temp;
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
					(perror("execve"), free_shell(shell, 1, 1));
			}
		}
		else
			malloc_error(shell, 1, 1);
	}
}

void	access_absolute(t_mshell *shell, char **env)
{
	if (!access(shell->command[0], F_OK | X_OK))
		execve(shell->command[0], shell->command, env);
}

char	**get_path(t_mshell *shell, char **env)
{
	t_param	*path;

	path = get_param(shell->params, "PATH");
	if (path && path->value)
		return (ft_split((path->value), ':'));
	else
	{
		command_error(shell, NULL, ": No such file or directory", 127);
		free_shell(shell, 1, shell->exit_code);
	}
	return (NULL);
}

int	execute_external(t_mshell *shell, char **env)
{
	pid_t	pid;
	int		i;
	char	**path;
	char	*exec;

	pid = fork();
	if (pid == 0)
	{
		access_absolute(shell, env);
		path = get_path(shell, env);
		if (!path || !path[0])
		{
			command_error(shell, NULL, ": No such file or directory", 127);
			free_shell(shell, 1, 127);
		}
		is_accessible(shell, path, env);
		command_error(shell, NULL, ": command not found", 127);
		(ft_free(path), free_shell(shell, 1, 127));
	}
	else
	{
		waitpid(pid, &shell->exit_code, 0);
		shell->exit_code = WEXITSTATUS(shell->exit_code);
	}
	return (0);
}
