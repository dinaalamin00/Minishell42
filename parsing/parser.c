/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:58:47 by mafaisal          #+#    #+#             */
/*   Updated: 2024/04/24 09:52:51 by mafaisal         ###   ########.fr       */
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

int	parser(t_mshell *shell)
{
	if (!expand_params(shell))
		return (EXIT_FAILURE);
	if (!parse_files(shell))
		return (EXIT_FAILURE);
	if (!clean_command(shell))
		return (EXIT_FAILURE);
	ft_free(shell->tokens);
	shell->tokens = NULL;
	return (EXIT_SUCCESS);
}
