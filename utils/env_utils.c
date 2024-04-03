/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:38:46 by mafaisal          #+#    #+#             */
/*   Updated: 2024/03/29 11:19:14 by mafaisal         ###   ########.fr       */
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

void	add_var(t_param **param, char *key, char *value)
{
	t_param	*node;

	node = malloc(sizeof(t_param));
	// if (!node)
	// 	return (NULL); // should we free the params list?
	node->key = key;
	node->value = value;
	node->next = NULL;
	node->next = *param;
	*param = node;
}

void	env_to_list(t_mshell *shell, char **env)
{
	char	*assign;
	char	*key;
	char	*value;
	int		i;

	i = 0;
	while (env[i])
	{
		assign = ft_strchr(env[i], '=');
		key = ft_strccpy(env[i], "=");
		value = ft_strdup(assign + 1);
		add_var(&(shell->params), key, value);
		i++;
	}
	i = 0;
}

t_param	*get_param(t_param *params, char *key)
{
	t_param	*param;

	// printf("param key: %s\n", key);
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
