/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:54:19 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/29 12:14:27 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	close_quote(char **str, char *next_str)
{
	char	*temp;

	if (ft_strset(next_str, "\'\""))
	{
		temp = ft_strdup("\"");
		if (!temp)
			return (FAILURE);
		temp = ft_strjoin(temp, *str);
		if (!temp)
			return (FAILURE);
		temp = ft_strjoin(temp, "\"");
		if (!temp)
			return (FAILURE);
		free(*str);
		*str = temp;
	}
	return (SUCCESS);
}

void	quote_str(t_mshell *shell, int i)
{
	char	*temp;

	close_quote(&shell->tokens[i], "\"");
	if (!ft_strset(shell->tokens[i - 1], "\'\"") && i > 0)
	{
		temp = ft_str_join(" ", shell->tokens[i]);
		free(shell->tokens[i]);
		shell->tokens[i] = temp;
	}
	if (!ft_strset(shell->tokens[i + 1], "\'\"") && shell->tokens[i + 1])
		shell->tokens[i] = ft_strjoin(shell->tokens[i], " ");
}
