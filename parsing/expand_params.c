/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:30:47 by mafaisal          #+#    #+#             */
/*   Updated: 2024/04/06 11:11:34 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	expand_key(t_mshell *shell, char **str)
{
	char	*key;
	char	*before;
	t_param	*param;
	char	*temp;

	temp = *(str);
	key = ft_strccpy(ft_strchr((temp), '$') + 1, "\"\'$ \t");
	before = ft_strccpy(temp, "$");
	param = get_param(shell->params, key);
	if (param)
		*(str) = ft_strjoin(before, param->value);
	else
	{
		*(str) = ft_strdup(before);
		free(before);
	}
	if (key && ft_strset(ft_strchr(temp, '$') + 1, "\"\' $\t"))
		*(str) = ft_strjoin(*(str),
				ft_strset(ft_strchr(temp, '$') + 1, "\"\' \t$"));
	free(key);
}

void	special_expand(int pipe_exit, char **str)
{
	char	*before;
	char	*exit_status;
	char	*start;

	start = ft_strchr(*(str), '$');
	before = ft_strccpy(*(str), "$");
	if (*(start + 1) == '?')
	{
		exit_status = ft_itoa(pipe_exit);
		*(str) = ft_strjoin(before, exit_status);
		*(str) = ft_strjoin(*(str), start + 2);
		free(exit_status);
	}
	else
		*(str) = ft_strjoin(before, ft_strchr(*(str), '$') + 2);
}

void	expand_string(t_mshell *shell, char **str)
{
	char	*temp;

	while (ft_strchr(*(str), '$'))
	{
		temp = *(str);
		if (ft_strchr(*(str), '$')
			&& (*(ft_strchr(*(str), '$') + 1) == '?'
				|| *(ft_strchr(*(str), '$') + 1) == '$'))
			special_expand(shell->pipe_exit, str);
		else if (ft_strchr(*(str), '$'))
			expand_key(shell, str);
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
			expand_string(shell, &(shell->tokens[i]));
		i++;
	}
}
