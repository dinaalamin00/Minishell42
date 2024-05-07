/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:48:47 by diahmed           #+#    #+#             */
/*   Updated: 2024/05/01 08:18:04 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
		perror(NULL);
	free_shell(shell, param_flag, exit_flag);
}
