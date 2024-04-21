/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:55:19 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/21 16:43:04 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handler(int signum)
{
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		// exit_code = 1;
	}
}

void	check_signal(void)
{
	struct sigaction	sa;

	sa.sa_handler = &handler;
	// if (sigemptyset(&sa.sa_mask) < 0)
	// 	perror("Error initializing sigset");
	// if (sigaddset(&sa.sa_mask, SIGQUIT) < 0)
	// 	perror("Error adding signal to set");
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGINT, &sa, NULL) < 0)
		perror("SIGINT Error");
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		perror("SIGQUIT Error");
}
