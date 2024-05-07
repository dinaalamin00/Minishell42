/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:38:46 by mafaisal          #+#    #+#             */
/*   Updated: 2024/05/04 10:53:25 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_paramlen(t_param *lst)
{
	int		cnt;
	t_param	*temp;

	temp = lst;
	cnt = 0;
	while (temp)
	{
		cnt++;
		temp = temp -> next;
	}
	return (cnt);
}

char	**list_to_env(t_mshell *shell)
{
	char	**env;
	t_param	*params;
	int		i;

	params = shell->params;
	env = malloc((ft_paramlen(params) + 1) * sizeof(char *));
	if (!env)
		return (malloc_error(shell, 0, -1), NULL);
	i = 0;
	while (params)
	{
		env[i] = ft_str_join(params->key, "=");
		if (!env[i])
			return (ft_free(env), NULL);
		if (params->value)
			env[i] = ft_strjoin(env[i], params->value);
		if (!env[i])
			return (ft_free(env), NULL);
		i++;
		params = params->next;
	}
	env[i] = NULL;
	return (env);
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
		free(key);
		free(node->value);
		node->value = NULL;
	}
	node->value = value;
	return (SUCCESS);
}

bool	add_var(t_mshell *shell, char *str)
{
	char	*assign;
	char	*key;
	char	*value;

	key = ft_strccpy(str, "=");
	if (!key)
		return (FAILURE);
	assign = ft_strchr(str, '=');
	if (assign)
	{
		value = ft_strdup(assign + 1);
		if (!value)
			return (free(key), FAILURE);
	}
	else
		value = NULL;
	if (valid_key(key) && param_lstadd(shell, key, value))
		return (SUCCESS);
	else
	{
		(free(key), free(value));
		return (FAILURE);
	}
}

t_param	*get_param(t_param *params, char *key)
{
	t_param	*param;

	param = params;
	if (!key)
		return (NULL);
	while (param && param->key)
	{
		if (!ft_strncmp(param->key, key, ft_strlen(key) + 1))
			return (param);
		param = param->next;
	}
	return (NULL);
}
