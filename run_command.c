/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:33:14 by mafaisal          #+#    #+#             */
/*   Updated: 2024/05/03 13:07:03 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	run_command(t_mshell *shell, char **env)
{
	int	exit_value;

	check_signal(shell);
	exit_value = pipe_check(shell);
	if (exit_value == EXIT_FAILURE)
	{
		shell->exit_code = exit_value;
		return ;
	}
	exit_value = lexer(shell);
	if (exit_value == EXIT_FAILURE)
	{
		shell->exit_code = exit_value;
		return ;
	}
	exit_value = parser(shell);
	if (exit_value == EXIT_FAILURE)
	{
		shell->exit_code = exit_value;
		return ;
	}
	executor(shell, env);
}
