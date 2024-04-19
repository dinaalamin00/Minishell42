/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:33:14 by mafaisal          #+#    #+#             */
/*   Updated: 2024/04/19 16:02:02 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	run_command(t_mshell *shell, char **env)
{
	lexer(shell);
	parser(shell, env);
	executor(shell, env);
	// if (lexer(shell))
	// {
	// 	if (parser(shell, env))
	// 		shell->exit_code = executor(shell, env);
	// 	else
	// 		shell->exit_code = 1;
	// }
	// else
	// 	shell->exit_code = 1;
}
