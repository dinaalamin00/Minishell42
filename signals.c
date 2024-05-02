/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:55:19 by diahmed           #+#    #+#             */
/*   Updated: 2024/05/01 17:56:37 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handler(int signum)
{
	// write(2, ":::\n", 4);
	if (signum == SIGINT)
	{
		signal_num = SIGINT;
		printf("main handlern\n");
		printf("\033[1;32m");
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		printf("\033[0m");
	}
}

void	heredoc_handler(int signum)
{
	// write(2, ":::\n", 4);
	if (signum == SIGINT)
	{
		printf("heredoc handlern\n");
		signal_num = SIGINT;
		exit(1);
	}
}

void	heredoc_parent_signal(int signum)
{
	// write(2, ":::\n", 4);
	if (signum == SIGINT)
	{
		printf("heredoc parent\n");
		rl_replace_line("", 0);
		rl_redisplay();
	}
}
void	exec_handler(int signum)
{
	// write(2, "::exec:\n", 4);
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		printf("child handlern\n");
		exit(130);
	}
	if (signum == SIGQUIT)
	{
		write(1, "QUIT: \n", 7);
		printf("child handlern\n");
		exit(131);
	}
}


void	check_signal(t_mshell *shell)
{
	struct sigaction	sa;

	ft_bzero(&sa, sizeof(sa));
	sa.sa_handler = &handler;
	sa.sa_flags = SA_RESTART;
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		perror("SIGQUIT Error");
	if (sigaction(SIGINT, &sa, NULL) < 0)
		perror("SIGINT Error");
	else if (signal_num == SIGINT)
	{
		shell->exit_code = 1;
		signal_num = -1;
	}
}
