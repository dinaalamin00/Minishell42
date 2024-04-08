/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:00:40 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/08 17:03:42 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	env_error(t_mshell *shell)
{
	ft_putstr_fd(shell->command[0], 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(shell->command[1], 2);
	ft_putendl_fd(": No such file or directory", 2);
}

void	ft_env(t_mshell *shell, int export)
{
    t_param	*var;

	if (array_len(shell->command) > 1)
	{
		env_error(shell);
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
