/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_external.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:02:27 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/17 19:33:54 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*is_accessible(char *path, char *command)
{
	char	*temp;
	char	*exec;

	if (!access(command, F_OK | X_OK))
		return (command);
	// exec = NULL;
	exec = ft_str_join(path, "/");
	if (exec)
		exec = ft_strjoin(exec, command);
	if (!access(exec, F_OK | X_OK))
		return (exec);
	if (exec)
		free(exec);
	return (NULL);
}

void	execute_external(t_mshell *shell, char **env)
{
	pid_t	pid;
	int		i;
	char	**path;
	char	*exec;

	pid = fork();
	if (pid == 0)
	{
		path = ft_split((get_param(shell->params, "PATH")->value), ':');
		if (!path)
			free_shell(shell, 1, 1);
		i = 0;
		while (path && path[i])
		{
			exec = is_accessible (path[i++], shell->command[0]);
			if (exec)
			{
				execve(exec, shell->command, env);
				(perror("execve"), exit (1)); // replace by function to free and exit
			}
		}
		command_error(shell, NULL, ": command not found");
		(ft_free(path), exit (1));
	}
	wait(NULL);
}
