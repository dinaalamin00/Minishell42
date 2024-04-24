/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:58:49 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/24 11:38:35 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_mshell	shell;

	ft_bzero(&shell, sizeof(t_mshell));
	env_to_list(&shell, envp);
	check_signal(&shell);
	while (1)
	{
		printf("\033[1;32m");
		shell.user_input = readline("minishell $ \033[0m");
		add_history(shell.user_input);
		if (!shell.user_input || ft_strncmp(shell.user_input, "exit", 5) == 0)
			ft_exit(&shell);
		run_command(&shell, envp);
	}
	free_shell(&shell, 1, 0);
	return (0);
	(void) argc;
	(void) argv;
}
