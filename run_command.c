/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:33:14 by mafaisal          #+#    #+#             */
/*   Updated: 2024/03/29 18:32:29 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	run_command(t_mshell *shell, char **env)
{
	lexer(shell);
	parser(shell, env);
	// for (int i = 0; shell->tokens[i]; i++)
	// 	printf("\033[1;41mtoken: (%s)\033[0m\n", shell->tokens[i]);
	for (int i = 0; shell->tokens[i]; i++)
		printf("(%s)\n", shell->tokens[i]);
	// ft_free(shell->tokens);
	free_params(shell->params);
	// check_files(shell);
	// open_dup(shell);
	// refactor_command(shell);
	// executor(shell, env);
	exit(0);
}
