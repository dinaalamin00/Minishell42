/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:02:51 by mafaisal          #+#    #+#             */
/*   Updated: 2024/04/26 08:59:01 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_alldigit(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i])
		return (0);
	return (1);
}

int	ft_exit(t_mshell *shell)
{
	int	exit_code;

	exit_code = 0;
	printf("exit\n");
	if (array_len(shell->command) > 2)
	{
		if (is_alldigit(shell->command[1]))
			command_error(shell, NULL, ": too many arguments", 1);
		else
			command_error(shell, NULL, ": numeric argument required", 1);
		return (EXIT_FAILURE);
	}
	else if (shell->command && shell->command[1])
	{
		if (is_alldigit(shell->command[1]))
			exit_code = ft_atoi(shell->command[1]);
		else
		{
			command_error(shell, NULL, ": numeric argument required", 255);
			exit_code = 255;
		}
	}
	free_shell(shell, 1, exit_code);
	return (EXIT_FAILURE);
}
