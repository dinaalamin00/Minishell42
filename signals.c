/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:55:19 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/24 11:41:48 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handler(int signum)
{
	if (signum == SIGINT)
	{
		printf("\033[1;32m");
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		printf("\033[0m");
	}
}

void	check_signal(t_mshell *shell)
{
	struct sigaction	sa;

	ft_bzero(&sa, sizeof(sa));
	sa.sa_handler = &handler;
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGINT, &sa, NULL) < 0)
		perror("SIGINT Error");
	// else
	// 	shell->exit_code = 1;
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		perror("SIGQUIT Error");
	(void) shell;
}
