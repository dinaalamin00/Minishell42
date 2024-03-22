/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:58:49 by diahmed           #+#    #+#             */
/*   Updated: 2024/03/22 14:16:43 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_mshell	shell;
	pid_t		pid;
	int			input_len;

	while (1)
	{
		shell.user_input = readline("$ ");
		input_len = ft_strlen(shell.user_input) + 1;
		if (!ft_strncmp(shell.user_input, "exit", input_len))
			break ;
		pid = fork();
		if (!pid)
			run_command(&shell, envp);
		wait(NULL);
	}
	return (0);
}
