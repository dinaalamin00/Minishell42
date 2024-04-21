/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:48:47 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/21 15:00:58 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_shell(t_mshell *shell, int param_flag, int exit_flag)
{
	if (shell->user_input)
		free(shell->user_input);
	if (shell->tokens)
		ft_free(shell->tokens);
	if (shell->command)
		ft_free(shell->command);
	if (shell->stdfile)
		flst_clear(&(shell->stdfile));
	shell->user_input = NULL;
	shell->tokens = NULL;
	shell->command = NULL;
	shell->stdfile = NULL;
	if (shell->params && param_flag)
	{
		free_params(shell->params);
		shell->params = NULL;
	}
	if (exit_flag >= 0)
		exit(exit_flag);
}

void	key_error(char *cmd, char *key)
{
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": `", 2);
	ft_putstr_fd(key, 2);
	ft_putendl_fd("\': not a valid identifier", 2);
}

int	command_error(t_mshell *shell, t_param	*path, char *message, int code)
{
	ft_putstr_fd(shell->command[0], 2);
	if (path || (!ft_strncmp("exit", shell->command[0], 5)
			&& !is_alldigit(shell->command[1])))
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(shell->command[1], 2);
	}
	ft_putendl_fd(message, 2);
	return (code);
}

void	malloc_error(t_mshell *shell, int param_flag, int exit_flag)
{
	if (errno == ENOMEM)
		perror("Error: ");
	free_shell(shell, param_flag, exit_flag);
}
