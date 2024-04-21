/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:33:14 by mafaisal          #+#    #+#             */
/*   Updated: 2024/04/21 12:24:45 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	run_command(t_mshell *shell, char **env)
{
	int	exit;

	exit = lexer(shell);
	if (exit == EXIT_FAILURE)
	{
		shell->exit_code = exit;
		return ;
	}
	exit = parser(shell, env);
	if (exit == EXIT_FAILURE)
	{
		shell->exit_code = exit;
		return ;
	}
	shell->exit_code = executor(shell, env);
}
