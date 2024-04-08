/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:58:47 by mafaisal          #+#    #+#             */
/*   Updated: 2024/04/08 17:36:57 by mafaisal         ###   ########.fr       */
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
	parse_files(shell);
	clean_command(shell);
	ft_free(shell->tokens);
}
