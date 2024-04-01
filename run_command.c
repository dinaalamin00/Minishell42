/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:33:14 by mafaisal          #+#    #+#             */
/*   Updated: 2024/04/01 15:11:54 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display(t_flist *file)
{
	while(file)
	{
		printf("name : (%s)\tmode : %d\n", file->name, file->mode);
		file = file ->next;
	}
}
void	run_command(t_mshell *shell, char **env)
{
	lexer(shell);
	parser(shell, env);
	for (int i = 0; shell->tokens[i]; i++)
		printf("(%s)\n", shell->tokens[i]);
	display(shell->stdfile);
	ft_free(shell->tokens);
	free_params(shell->params);
	executor(shell);
	// executor(shell, env);
	exit(0);
}
