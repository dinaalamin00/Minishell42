/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:33:14 by mafaisal          #+#    #+#             */
/*   Updated: 2024/04/26 16:34:51 by diahmed          ###   ########.fr       */
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
	exit = parser(shell);
	if (exit == EXIT_FAILURE)
	{
		shell->exit_code = exit;
		return ;
	}
	executor(shell, env);
}
