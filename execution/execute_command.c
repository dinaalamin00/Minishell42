/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:53:20 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/08 14:35:52 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_command(t_mshell *shell, char **env)
{
    char    *lower_cmd;
    
    lower_cmd = ft_str_tolower(ft_strdup(shell->command[0]));
	if (!ft_strncmp(lower_cmd, "pwd", 4))
		ft_pwd(shell);
	// else if (!ft_strncmp(shell->command[0], "cd", 3))
	// 	ft_cd(shell, env);
	// else if (!ft_strncmp(shell->command[0], "echo", 3))
	// 	ft_echo(shell, env);
	else if (!ft_strncmp(shell->command[0], "env", 4))
		ft_env(shell, 0);
	// else if (!ft_strncmp(shell->command[0], "export", 3))
	// 	ft_export(shell, env);
	else if (!ft_strncmp(shell->command[0], "unset", 6))
		ft_unset(shell);
	// else
    free(lower_cmd);
	// 	execute_external(shell, env);
}
