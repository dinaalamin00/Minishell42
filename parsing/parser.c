/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:58:47 by mafaisal          #+#    #+#             */
/*   Updated: 2024/04/26 12:11:40 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

bool token_remainder(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		if (*tokens[i])
			return (1);
		i++;
	}
	return (0);
}

int	parser(t_mshell *shell)
{
	if (!parse_files(shell))
		return (EXIT_FAILURE);
	if (!expand_params(shell))
		return (EXIT_FAILURE);
	// if (!expand_files(shell))
	// 	return (EXIT_FAILURE);
	if (token_remainder(shell->tokens))
	{
		if (!clean_command(shell))
			return (EXIT_FAILURE);
	}
	ft_free(shell->tokens);
	shell->tokens = NULL;
	return (EXIT_SUCCESS);
}

