/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:43:11 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/17 18:53:07 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*get_file(t_mshell *shell, int i, int *mode)
{
	char	*file_name;

	if (shell->tokens[i][0] == '<')
	{
		if (shell->tokens[i][1] == '<')
			*mode = HERE_DOC;
		else if (shell->tokens[i][1] == '>')
			*mode = RDWR;
		else if (!shell->tokens[i][1])
			*mode = RD;
	}
	else if (shell->tokens[i][0] == '>')
	{
		if (shell->tokens[i][1] == '>')
			*mode = APPEND;
		else if (!shell->tokens[i][1])
			*mode = WR;
	}
	file_name = ft_strdup(shell->tokens[i + 1]);
	return (file_name);
}

void	parse_files(t_mshell *shell)
{
	int		i;
	int		mode;
	char	*file_name;

	join_quote(shell);
	i = 0;
	while (shell->tokens[i])
	{
		if (is_redirect(shell->tokens[i][0]))
		{
			file_name = get_file(shell, i, &mode);
			file_name = custom_trim(file_name, 32, 0);
			if (!file_name)
			{
				ft_putendl_fd("Malloc error! Free up some space", 2);
				free_shell(shell, 0, -1);
				return ;
			}
			if (ft_strset(file_name, "\'\"") && mode != HERE_DOC)
				file_name = custom_trim(file_name, *file_name, 0);
			if (!file_name)
			{
				ft_putendl_fd("Malloc error! Free up some space", 2);
				free_shell(shell, 0, -1);
				return ;
			}
			flst_addback(&(shell->stdfile), file_name, mode);
			free(shell->tokens[i]);
			shell->tokens[i] = ft_strdup("");
			if (!shell->tokens[i])
			{
				ft_putendl_fd("Malloc error! Free up some space", 2);
				free_shell(shell, 0, -1);
				return ;
			}
			i++;
			free(shell->tokens[i]);
			shell->tokens[i] = ft_strdup("");
			if (!shell->tokens[i])
			{
				ft_putendl_fd("Malloc error! Free up some space", 2);
				free_shell(shell, 0, -1);
				return ;
			}
		}
		i++;
	}
}
