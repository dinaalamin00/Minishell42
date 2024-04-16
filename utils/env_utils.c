/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:38:46 by mafaisal          #+#    #+#             */
/*   Updated: 2024/04/16 12:23:39 by mafaisal         ###   ########.fr       */
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

void	env_to_list(t_mshell *shell, char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		add_var(shell, env[i]);
		i++;
	}
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
