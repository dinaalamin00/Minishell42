/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:58:49 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/08 12:37:23 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_mshell	shell;
	pid_t		pid;
	int			input_len;
	char		*scanned;

	ft_bzero(&shell, sizeof(shell));
	while (1)
	{
		printf("\033[1;32m");
		shell.user_input = readline("minishell $ \033[0m");
		input_len = ft_strlen(shell.user_input) + 1;
		if (ft_strncmp(shell.user_input, "exit", 5) == 0)
			break ;
		pid = fork();
		if (!pid)
			run_command(&shell, envp);
		wait(NULL);
		if (pid)
			free(shell.user_input);
	}
	return (0);
}
