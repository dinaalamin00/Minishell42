/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_accessibility.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 08:23:06 by mafaisal          #+#    #+#             */
/*   Updated: 2024/05/05 14:10:21 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_errno(t_mshell *shell, char **env)
{
	if (errno == EACCES)
	{
		ft_free(env);
		command_error(shell, NULL, "Permission denied", 126);
		free_shell(shell, 1, 126);
	}
	else if (errno == EISDIR)
	{
		ft_free(env);
		printf("%s: ", shell->command[0]);
		command_error(shell, NULL, "is a directory", 126);
		free_shell(shell, 1, 126);
	}
}

void	is_accessible_relative(t_mshell *shell, char **path, char **env)
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
			(free(exec), ft_free(env), malloc_error(shell, 1, 1));
		if (exec)
		{
			if (!access(exec, F_OK | X_OK))
			{
				execve(exec, shell->command, env);
				check_errno(shell, env);
				(free(exec), perror("execve"),
					ft_free(env), free_shell(shell, 1, 1));
			}
			free(exec);
		}
		else
			(free(exec), ft_free(env), malloc_error(shell, 1, 1));
	}
}

void	is_accessible_absolute(t_mshell *shell, char **env)
{
	if (!access(shell->command[0], F_OK | X_OK))
		execve(shell->command[0], shell->command, env);
	check_errno(shell, env);
}
