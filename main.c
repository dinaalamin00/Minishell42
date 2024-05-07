/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:58:49 by diahmed           #+#    #+#             */
/*   Updated: 2024/05/06 09:24:09 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_mshell	shell;

	shell = init_shell(envp);
	check_signal(&shell);
	while (1)
	{
		printf("\033[1;32m");
		shell.user_input = readline("minishell $ \033[0m");
		shell.file_err = 0;
		if (shell.user_input && *shell.user_input)
			add_history(shell.user_input);
		if (!shell.user_input || ft_strncmp(shell.user_input, "exit", 5) == 0)
			ft_exit(&shell);
		if (!is_empty(shell.user_input))
			run_command(&shell);
		else
			free(shell.user_input);
		free_shell(&shell, 0, -1);
	}
	return (0);
	(void) argc;
	(void) argv;
}
