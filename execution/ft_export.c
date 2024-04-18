/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:19:52 by mafaisal          #+#    #+#             */
/*   Updated: 2024/04/18 14:15:34 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	valid_key(char *key)
{
	int	i;

	if (!ft_isalpha(key[0]) && key[0] != '_')
		return (0);
	i = 1;
	while (key[i])
	{
		if (!ft_isdigit(key[i]) && !ft_isalpha(key[i]) && key[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

int	valid_value(char *value)
{
	if (!value)
		return (1);
	return (1);
}

void	param_lstadd(t_mshell *shell, t_param **param, char *key, char *value)
{
	t_param	*node;

	node = get_param(*param, key);
	if (!node)
	{
		node = malloc(sizeof(t_param));
		if (!node)
		{
			free(key);
			if (value)
				free(value);
			free_shell(shell, 1, 1);
		}
		node->key = key;
		node->next = *param;
		*param = node;
	}
	else if (node && node->value)
	{
		free(node->value);
		node->value = NULL;
	}
	node->value = value;
}

void	add_var(t_mshell *shell, char *str)
{
	t_param	*node;
	char	*assign;
	char	*key;
	char	*value;

	key = ft_strccpy(str, "=");
	if (!key)
		free_shell(shell, 1, 1);
	assign = ft_strchr(str, '=');
	if (assign)
	{
		value = ft_strdup(assign + 1);
		if (!value)
			(free(key), free_shell(shell, 1, 1));
	}
	else
		value = NULL;
	if (valid_key(key) && valid_value(value))
		param_lstadd(shell, &(shell->params), key, value);
	else
	{
		(free(key), free(value));
		printf("not a valid key\n");
		free_shell(shell, 0, -1);
	}
}

void	ft_export(t_mshell *shell)
{
	int		i;
	char	*env_var;

	i = 1;
	if (!shell->command[i])
		ft_env(shell, 1);
	while (shell->command[i])
	{
		add_var(shell, shell->command[i]);
		if (!shell->command)
			return ;
		i++;
	}
}
