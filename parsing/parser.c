/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:58:47 by mafaisal          #+#    #+#             */
/*   Updated: 2024/04/17 18:56:35 by mafaisal         ###   ########.fr       */
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

void	parser(t_mshell *shell, char **env)
{
	expand_params(shell);
	if (!shell->tokens)
		return ;
	parse_files(shell);
	if (!shell->tokens)
		return ;
	clean_command(shell);
	if (!shell->command)
		return ;
	ft_free(shell->tokens);
	shell->tokens = NULL;
}
