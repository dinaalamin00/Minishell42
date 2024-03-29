/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:30:47 by mafaisal          #+#    #+#             */
/*   Updated: 2024/03/29 11:39:43 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	expand_key(t_mshell *shell, char *temp, int i)
{
	char	*key;
	char	*before;
	t_param	*param;

	key = ft_strccpy(ft_strchr(temp, '$') + 1, "\"\'$ \t");
	before = ft_strccpy(temp, "$");
	param = get_param(shell->params, key);
	if (param)
		shell->tokens[i] = ft_strjoin(before, param->value);
	else
	{
		shell->tokens[i] = ft_strdup(before);
		free(before);
	}
	if (key && ft_strset(ft_strchr(temp, '$') + 1, "\"\' \t"))
		shell->tokens[i] = ft_strjoin(shell->tokens[i],
				ft_strset(ft_strchr(temp, '$') + 1, "\"\' \t$"));
	free(key);
}

void	expand_dollar(t_mshell *shell, char *temp, int i)
{
	char	*before;
	char	*exit_status;

	exit_status = ft_itoa(shell->pipe_exit);
	before = ft_strccpy(temp, "$");
	shell->tokens[i] = ft_strjoin(before, exit_status);
	shell->tokens[i] = ft_strjoin(shell->tokens[i], ft_strchr(temp, '$') + 2);
	free(exit_status);
}

void	expand_token(t_mshell *shell, int i)
{
	char	*temp;

	while (ft_strchr(shell->tokens[i], '$'))
	{
		temp = shell->tokens[i];
		if (ft_strchr(temp, '$') && *(ft_strchr(temp, '$') + 1) != '?')
			expand_key(shell, temp, i);
		else if (ft_strchr(temp, '$') && *(ft_strchr(temp, '$') + 1) == '?')
			expand_dollar(shell, temp, i);
		free(temp);
	}
}

void	expand_params(t_mshell *shell)
{
	char	*quote;
	int		i;

	i = 0;
	while (shell->tokens[i])
	{
		quote = ft_strset(shell->tokens[i], "\'\"");
		if (!quote || *quote != '\'')
			expand_token(shell, i);
		i++;
	}
}