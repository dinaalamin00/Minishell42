/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:55:19 by diahmed           #+#    #+#             */
/*   Updated: 2024/05/03 16:40:25 by diahmed          ###   ########.fr       */
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
		g_signal_num = SIGINT;
	}
}

void	heredoc_handler(int signum)
{
	if (signum == SIGINT)
		exit(1);
}

void	exec_handler(int signum)
{
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		exit(130);
	}
	if (signum == SIGQUIT)
	{
		write(1, "QUIT: \n", 7);
		exit(131);
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
	else if (g_signal_num == SIGINT)
	{
		shell->exit_code = 1;
		g_signal_num = -1;
	}
	if (sigaction(SIGQUIT, &sa, NULL) < 0)
		perror("SIGQUIT Error");
}
