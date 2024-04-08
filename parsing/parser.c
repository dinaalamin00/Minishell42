/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:58:47 by mafaisal          #+#    #+#             */
/*   Updated: 2024/04/08 16:48:38 by diahmed          ###   ########.fr       */
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
	// env_to_list(shell, env);
	expand_params(shell);
	parse_files(shell);
	clean_command(shell);
	ft_free(shell->tokens);
	display_command(shell->command);
	display(shell->stdfile);
}
