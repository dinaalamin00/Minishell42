/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:33:14 by mafaisal          #+#    #+#             */
/*   Updated: 2024/04/06 17:04:50 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	run_command(t_mshell *shell, char **env)
{
	lexer(shell);
	parser(shell, env);
	ft_free(shell->tokens);
	// for (int i = 0; shell->command[i]; i++)
	// 	printf("(%s)\n", shell->command[i]);
	// display(shell->stdfile);
	executor(shell, env);
	free_params(shell->params);
	ft_free(shell->command);
	// exit(0);
}
