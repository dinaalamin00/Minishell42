/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:43:11 by diahmed           #+#    #+#             */
/*   Updated: 2024/05/03 15:54:12 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*get_file(t_mshell *shell, int i, int *mode)
{
	char	*file_name;

	file_name = NULL;
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
	if (shell->tokens[i + 1])
		file_name = ft_strdup(shell->tokens[i + 1]);
	return (file_name);
}

static int	add_file(t_mshell *shell, int i)
{
	int		mode;
	char	*file_name;

	file_name = get_file(shell, i, &mode);
	if (!file_name)
		return (FAILURE);
	file_name = custom_trim(file_name, 32, 0);
	if (!file_name)
		return (FAILURE);
	if (ft_strset(file_name, "\'\"") && mode != HERE_DOC)
		file_name = custom_trim(file_name, *file_name, 0);
	if (!file_name)
		return (FAILURE);
	if (!flst_addback(&(shell->stdfile), file_name, mode))
		return (FAILURE);
	return (SUCCESS);
}

bool	parse_files(t_mshell *shell)
{
	int		i;

	i = 0;
	while (shell->tokens[i])
	{
		if (is_redirect(shell->tokens[i][0]))
		{
			if (add_file(shell, i) == FAILURE)
				return (malloc_error(shell, 0, -1), FAILURE);
			free(shell->tokens[i]);
			shell->tokens[i] = ft_strdup("");
			if (!shell->tokens[i])
				return (malloc_error(shell, 0, -1), FAILURE);
			i++;
			free(shell->tokens[i]);
			shell->tokens[i] = ft_strdup("");
			if (!shell->tokens[i])
				return (malloc_error(shell, 0, -1), FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}
