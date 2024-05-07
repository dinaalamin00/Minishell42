/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:30:47 by mafaisal          #+#    #+#             */
/*   Updated: 2024/05/06 09:32:47 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	expand_key(t_mshell *shell, char **str)
{
	char	*key;
	char	*before;
	t_param	*param;
	char	*temp;

	temp = *(str);
	key = ft_strccpy(ft_strchr((temp), '$') + 1, "\"\'$ \t\n");
	if (!key)
		return (FAILURE);
	before = ft_strccpy(temp, "$");
	if (!before)
		return (free(key), FAILURE);
	param = get_param(shell->params, key);
	if (param)
		*(str) = ft_str_join(before, param->value);
	else
		*(str) = ft_strdup(before);
	if (!*(str))
		return (free(key), free(before), FAILURE);
	if (key && ft_strset(ft_strchr(temp, '$') + 1, "\"\' $\t\n"))
		*(str) = ft_strjoin(*(str),
				ft_strset(ft_strchr(temp, '$') + 1, "\"\' \t$\n"));
	if (!*(str))
		return (free(key), free(before), FAILURE);
	return (free(key), free(before), SUCCESS);
}

bool	special_expand(int exit_code, char **str)
{
	char	*before;
	char	*exit_status;
	char	*start;

	start = ft_strchr(*(str), '$');
	before = ft_strccpy(*(str), "$");
	if (!before)
		return (FAILURE);
	exit_status = ft_itoa(exit_code);
	if (*(start + 1) == '?')
	{
		*(str) = ft_strjoin(before, exit_status);
		if (!*(str))
			return (free(before), free(exit_status), FAILURE);
		*(str) = ft_strjoin(*(str), start + 2);
		if (!*(str))
			return (free(before), free(exit_status), FAILURE);
	}
	else
	{
		*(str) = ft_strjoin(before, ft_strchr(*(str), '$') + 2);
		if (!*(str))
			return (free(exit_status), free(before), FAILURE);
	}
	return (free(exit_status), SUCCESS);
}

bool	expand_string(t_mshell *shell, char **str)
{
	char	*temp;

	while (ft_strchr(*(str), '$') && *(ft_strchr(*(str), '$') + 1) != '\0')
	{
		temp = *(str);
		if ((*(ft_strchr(*(str), '$') + 1) == '?'
				|| *(ft_strchr(*(str), '$') + 1) == '$'))
		{
			if (!special_expand(shell->exit_code, str))
				return (malloc_error(shell, 0, -1), FAILURE);
		}
		else if (ft_strchr(*(str), '$'))
		{
			if (!expand_key(shell, str))
				return (malloc_error(shell, 0, -1), FAILURE);
		}
		free(temp);
	}
	return (SUCCESS);
}

bool	expand_params(t_mshell *shell)
{
	char	*quote;
	int		i;

	i = 0;
	while (shell->tokens[i])
	{
		quote = ft_strset(shell->tokens[i], "\'\"");
		if (ft_strchr(shell->tokens[i], '$') && (!quote || *quote != '\''))
		{
			if (i > 0 && !ft_strncmp("<<", shell->tokens[i - 1], 3))
			{
				i++;
				continue ;
			}
			if (!expand_string(shell, &(shell->tokens[i])))
				return (FAILURE);
			if (!quote && ft_strset(shell->tokens[i], "<>|"))
				quote_str(shell, i);
		}
		i++;
	}
	return (SUCCESS);
}
