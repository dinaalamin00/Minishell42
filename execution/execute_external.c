/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_external.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:02:27 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/08 16:53:56 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*is_accessible(char *path, char *command)
{
	char	*temp;
	char	*exec;

	if (!access(command, R_OK | X_OK))
		return (command);
	exec = NULL;
	temp = exec;
	exec = ft_strjoin(path, "/");
	if (temp)
		// free(temp);
	temp = exec;
	exec = ft_strjoin(exec, command);
	// free(temp);
	if (!access(exec, R_OK | X_OK))
		return (exec);
	// free(exec);
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
		exec = NULL;
		if (getenv("PATH"))
		{
			path = ft_split (getenv("PATH"), ':');
			i = 0;
			while (path[i])
			{
				exec = is_accessible (path[i++], shell->command[0]);
				execve(exec, shell->command, env);
			}
			ft_putstr_fd(shell->command[0], 2);
			ft_putendl_fd(": command not found", 2);
			// ft_free(path);
			exit (1);
		}
	}
	wait(NULL);
}
