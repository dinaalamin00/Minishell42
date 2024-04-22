/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_external.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:02:27 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/22 13:06:48 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*is_accessible(char *path, char *command)
{
	char	*temp;
	char	*exec;

	if (!access(command, X_OK))
		return (command);
	exec = ft_str_join(path, "/");
	if (exec)
		exec = ft_strjoin(exec, command);
	else
		return (NULL);
	if (!access(exec, F_OK | X_OK))
		return (exec);
	if (exec)
		free(exec);
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
		if (!access(shell->command[0], F_OK | X_OK))
			execve(shell->command[0], shell->command, env);
		path = ft_split((get_param(shell->params, "PATH")->value), ':');
		i = 0;
		while (path && path[i])
		{
			exec = is_accessible (path[i++], shell->command[0]);
			if (exec)
			{
				execve(exec, shell->command, env);
				(perror("execve"), free_shell(shell, 1, 1));
			}
		}
		command_error(shell, NULL, ": command not found", 127);
		(ft_free(path), free_shell(shell, 1, 1));
	}
	return (wait(NULL), 1);
}
//error msg for null path "no such file or directory"
