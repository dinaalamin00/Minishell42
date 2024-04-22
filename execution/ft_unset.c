/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:28:34 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/22 09:11:01 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_param	*get_before(t_param *params, t_param *node)
{
	t_param	*before;

	before = params;
	while (before->next && before->next != node)
		before = before->next;
	return (before);
}

void	del_var(t_param **params, char *key)
{
	t_param	*node;
	t_param	*before_node;

	node = get_param(*params, key);
	if (!node)
		return ;
	if (*params == node)
		*params = node->next;
	else
	{
		before_node = get_before(*params, node);
		before_node->next = node->next;
	}
	free(node->key);
	free(node->value);
	free(node);
}

int	ft_unset(t_mshell *shell)
{
	int	i;
	int	exit_code;

	i = 1;
	exit_code = 0;
	while (shell->command[i])
	{
		if (!valid_key(shell->command[i]) || ft_strchr(shell->command[i], '='))
		{
			key_error("unset", shell->command[i]);
			exit_code = 1;
		}
		else
			del_var(&shell->params, shell->command[i]);
		i++;
	}
	return (exit_code);
}
