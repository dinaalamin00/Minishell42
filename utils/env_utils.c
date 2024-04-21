/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:38:46 by mafaisal          #+#    #+#             */
/*   Updated: 2024/04/21 14:49:58 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_params(t_param *params)
{
	t_param	*temp;

	temp = params;
	while (params)
	{
		temp = temp->next;
		free(params->key);
		free(params->value);
		free(params);
		params = temp;
	}
}

bool	param_lstadd(t_mshell *shell, char *key, char *value)
{
	t_param	*node;

	node = get_param(shell->params, key);
	if (!node)
	{
		node = malloc(sizeof(t_param));
		if (!node)
		{
			free(key);
			if (value)
				free(value);
			return (malloc_error(shell, 0, -1), FAILURE);
		}
		node->key = key;
		node->next = shell->params;
		shell->params = node;
	}
	else if (node && node->value)
	{
		free(node->value);
		node->value = NULL;
	}
	node->value = value;
	return (SUCCESS);
}

bool	add_var(t_mshell *shell, char *str)
{
	t_param	*node;
	char	*assign;
	char	*key;
	char	*value;

	key = ft_strccpy(str, "=");
	if (!key)
		return (malloc_error(shell, 1, -1), FAILURE);
	assign = ft_strchr(str, '=');
	if (assign)
	{
		value = ft_strdup(assign + 1);
		if (!value)
			return (free(key), malloc_error(shell, 1, -1), FAILURE);
	}
	else
		value = NULL;
	if (valid_key(key) && valid_value(value) && param_lstadd(shell, key, value))
		return (SUCCESS);
	else
	{
		(free(key), free(value));
		return (FAILURE);
	}
}

bool	env_to_list(t_mshell *shell, char **env)
{
	int	i;

	i = 0;
	while (env && env[i])
	{
		if (!add_var(shell, env[i]))
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

t_param	*get_param(t_param *params, char *key)
{
	t_param	*param;

	param = params;
	if (!key)
		return (NULL);
	while (param)
	{
		if (!ft_strncmp(param->key, key, ft_strlen(key) + 1))
			return (param);
		param = param->next;
	}
	return (NULL);
}
