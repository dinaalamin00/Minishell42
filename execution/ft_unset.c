/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:28:34 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/19 17:49:04 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	del_var(t_param **param, char *key)
{
	t_param	*curr;
	t_param	*next;

	curr = *param;
	next = curr -> next;
	if (!ft_strncmp(curr->key, key, ft_strlen(key) + 1))
	{
		free(curr->key);
		free(curr->value);
		*param = next;
		return ;
	}
	while (next != NULL)
	{
		next = curr -> next;
		if (!ft_strncmp(next->key, key, ft_strlen(key) + 1))
		{
			free(next->key);
			free(next->value);
			curr -> next = next->next;
		}
		else
			curr = curr->next;
	}
}

void	ft_unset(t_mshell *shell)
{
	int	i;

	i = 1;
	while (shell->command[i])
	{
		if (!valid_key(shell->command[i]) || ft_strchr(shell->command[i], '='))
			key_error("unset", shell->command[i]);
		else
			del_var(&shell->params, shell->command[i]);
		i++;
	}
}
