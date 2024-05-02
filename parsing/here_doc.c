/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:20:33 by diahmed           #+#    #+#             */
/*   Updated: 2024/05/01 17:54:43 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	heredoc_child(t_mshell *shell, char *name)
{
	if (signal(SIGINT, &heredoc_handler) == SIG_ERR)
			perror("SIGQUIT Error");
	close(fd[0]);
	line = get_next_line(0);
	if (!is_quote(*name))
		delimiter = ft_str_join(name, "\n");
	else
		delimiter = ft_strjoin(custom_trim(ft_strdup(name), *name, 0), "\n");
	while (line && ft_strncmp(line, delimiter, ft_strlen(delimiter) + 1) != 0)
	{
		if (!is_quote(*name))
			expand_string(shell, &line);
		ft_putstr_fd(line, fd[1]);
		free(line);
		line = get_next_line(0);
	}
	free(delimiter);
	free(line);
}

void	heredoc_parent(t_mshell *shell, char *name)
{
	if (signal(SIGINT, SIG_IGN) == SIG_ERR)
		perror("SIGQUIT Error");
	// if (signal(SIGINT, &heredoc_parent) == SIG_ERR)
	// perror("SIGINT Error")
	;
	waitpid(pid, &shell->exit_code, 0);
	close(fd[1]);
	shell->exit_code = WEXITSTATUS(shell->exit_code);
	// pri ntf("exit code : %d\n", shell->exit_code);
	if (shell->exit_code != 0)
	{
		// printf("hh::\n");
		check_signal(shell);
		shell->here_flag = 1;
		close(fd[0]);
		return ;
	}
	else
	{
		if (dup2(fd[0], STDIN_FILENO) < 0)
			perror(NULL);
		close(fd[0]);
	}
}

void	here_doc(t_mshell *shell, char *name)
{
	int		fd[2];
	pid_t	pid;
	char	*line;
	char	*delimiter;

	if (pipe(fd) < 0)
		return ;
	pid = fork();
	if (pid < 0)
	{
		perror(NULL);
		return ;
	}
	if (!pid)
	{
		heredoc_child(shell, name);
		exit(0);
	}
	else
	{
		heredoc_parent(shell, name);
		check_signal(shell);
	}
}
