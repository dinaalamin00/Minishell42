/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_quoted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:46:15 by diahmed           #+#    #+#             */
/*   Updated: 2024/05/03 18:05:18 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	last_element(char **array)
{
	int	i;

	i = 0;
	while (array[i + 1])
		i++;
	return (i);
}

static	char	*trim_str_back(char *str, char **spaces, char *new_string)
{
	if (ft_strset(new_string, "\'\""))
	{
		*spaces = ft_strrset(new_string, "\'\"");
		str = custom_trim(str, 32, 2);
		str = custom_trim(str, **spaces, 2);
	}
	return (str);
}

static char	**join_to_last(char **array, char *new_string)
{
	char	*new_temp;
	char	symbol;
	char	*spaces;
	int		i;

	i = last_element(array);
	symbol = 0;
	if (ft_strset(array[i], "\'\""))
		symbol = array[i][ft_strlen(array[i]) - 1];
	new_temp = ft_strdup(new_string);
	if (ft_strset(new_string, "\'\""))
		new_temp = custom_trim(new_temp, *new_temp, 1);
	if (!new_temp)
		return (NULL);
	array[i] = ft_strjoin(custom_trim(custom_trim(array[i], 32, 0), symbol, 0),
			new_temp);
	array[i] = trim_str_back(array[i], &spaces, new_string);
	if (!array[i] || !close_quote(&array[i], new_string))
		return (free(new_temp), NULL);
	if (ft_strset(new_string, "\'\""))
		array[i] = ft_strjoin(array[i], spaces + 1);
	return (free(new_temp), array);
}

static int	to_be_joined(char **array, char *new)
{
	int	i;

	i = last_element(array);
	if (is_redirect(array[i][0]) || is_redirect(new[0]))
		return (0);
	if (ft_strset(array[i], "\'\""))
	{
		if (is_quote(array[i][ft_strlen(array[i]) - 1]))
		{
			if (is_quote(new[0]) || !ft_strset(new, "\'\""))
				return (1);
		}
		else
			return (0);
	}
	else
	{
		if (ft_strset(new, "\'\"") && is_quote(new[0]))
			return (1);
	}
	return (0);
}

bool	join_quote(t_mshell *shell)
{
	char	**new_token;
	int		i;

	i = 0;
	new_token = malloc(1 * sizeof(char *));
	if (!new_token)
		return (FAILURE);
	new_token[0] = NULL;
	while (shell->tokens[i])
	{
		new_token = append_to_array(shell, new_token,
				ft_strdup(shell->tokens[i]));
		if (!new_token)
			return (FAILURE);
		while (shell->tokens[i + 1]
			&& to_be_joined(new_token, shell->tokens[i + 1]))
		{
			i++;
			new_token = join_to_last(new_token, shell->tokens[i]);
			if (!new_token)
				return (FAILURE);
		}
		i++;
	}
	return (ft_free(shell->tokens), shell->tokens = new_token, SUCCESS);
}
