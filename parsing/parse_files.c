/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:43:11 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/01 16:20:28 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_file(t_mshell *shell, int i)
{
	int		mode;
	char	*file_name;

	if (shell->tokens[i][0] == '<')
	{
		if (shell->tokens[i][1] == '<')
			mode = HERE_DOC;
		else if (shell->tokens[i][1] == '>')
			mode = RDWR;
		else if (!shell->tokens[i][1])
			mode = RD;
	}
	else if (shell->tokens[i][0] == '>')
	{
		if (shell->tokens[i][1] == '>')
			mode = APPEND;
		else if (!shell->tokens[i][1])
			mode = WR;
	}
	file_name = ft_strdup(shell->tokens[i + 1]);
	if (ft_strset(file_name, "\'\""))
		file_name = custom_trim(custom_trim(file_name, 32, 0), *file_name, 0);
	flst_addback(&(shell->stdfile), file_name, mode);
}

void	parse_files(t_mshell *shell)
{
	int	i;

	join_quote(shell);
	i = 0;
	while (shell->tokens[i])
	{
		if (is_redirect(shell->tokens[i][0]))
		{
			add_file(shell, i);
			free(shell->tokens[i]);
			shell->tokens[i] = ft_strdup("");
			i++;
			free(shell->tokens[i]);
			shell->tokens[i] = ft_strdup("");
		}
		i++;
	}
}
