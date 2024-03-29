/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:58:49 by diahmed           #+#    #+#             */
/*   Updated: 2024/03/29 13:06:51 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_mshell	shell;
	pid_t		pid;
	int			input_len;

	(void)argc;
	(void)argv;
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
	if (shell.tokens)
		ft_free(shell.tokens);
	return (0);
}
