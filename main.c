/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:58:49 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/19 18:17:14 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_mshell	shell;
	pid_t		pid;
	int			input_len;

	ft_bzero(&shell, sizeof(t_mshell));
	if (!env_to_list(&shell, envp))
		return (1);
	while (1)
	{
		printf("\033[1;32m");
		shell.user_input = readline("minishell $ \033[0m");
		add_history(shell.user_input);
		run_command(&shell, envp);
	}
	free_shell(&shell, 1, 0);
	return (0);
}
