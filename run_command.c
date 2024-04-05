/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:33:14 by mafaisal          #+#    #+#             */
/*   Updated: 2024/04/05 11:59:22 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display(t_flist *file)
{
	while (file)
	{
		printf("file : (%s)\tmode : %d\n", file->name, file->mode);
		file = file->next;
	}
}

void	display_command(char **command)
{
	int	i;

	i = 0;
	while (command[i])
	{
		printf("(%s) ", command[i]);
		i++;
	}
	printf("\n");
}

void	run_command(t_mshell *shell, char **env)
{
	lexer(shell);
	parser(shell, env);
	ft_free(shell->tokens);
	display_command(shell->command);
	display(shell->stdfile);
	executor(shell, env);
	free_params(shell->params);
	exit(0);
}
