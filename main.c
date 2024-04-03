/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:58:49 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/01 16:01:24 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_mshell	shell;
	pid_t		pid;
	int			input_len;
	char	*scanned;
	ft_bzero(&shell, sizeof(shell));
	while (1)
	{
		scanf("%s", scanned);
		(&shell)->user_input = ft_strdup(scanned);
		input_len = ft_strlen(shell.user_input) + 1;
		if (!ft_strncmp(shell.user_input, "exit", input_len))
			break ;
		pid = fork();
		if (!pid)
			run_command(&shell, envp);
		wait(NULL);
	}
	// free(shell.user_input);
	return (0);
}
