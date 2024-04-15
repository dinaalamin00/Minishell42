/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:00:40 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/15 16:50:32 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_env(t_mshell *shell, int export)
{
	t_param	*var;
	t_param	*path;

	path = get_param(shell->params, "PATH");
	if (array_len(shell->command) > 1 || !path)
	{
		command_error(shell, path, ": No such file or directory");
		return ;
	}
	var = shell->params;
	while (var)
	{
		if (!export && var->value)
			printf("%s=%s\n", var->key, var->value);
		else if (export)
		{
			printf("declare -x %s", var->key);
			if (var->value)
				printf("=\"%s\"", var->value);
			printf("\n");
		}
		var = var->next;
	}
}
