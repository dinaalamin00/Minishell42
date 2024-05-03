/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:20:33 by diahmed           #+#    #+#             */
/*   Updated: 2024/05/03 15:23:43 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	heredoc_child(t_mshell *shell, char *name, int fd[2])
{
	char	*line;
	char	*delimiter;

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
	close(fd[1]);
	exit(0);
}

static int	heredoc_parent(t_mshell *shell, int fd[2])
{
	close(fd[1]);
	if (shell->exit_code != 0)
	{
		check_signal(shell);
		close(fd[0]);
		return (-1);
	}
	else
	{
		if (dup2(fd[0], STDIN_FILENO) < 0)
			perror(NULL);
		close(fd[0]);
	}
	return (0);
}

int	here_doc(t_mshell *shell, char *name)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) < 0)
		return (perror(NULL), -1);
	pid = fork();
	if (pid < 0)
		return (perror(NULL), -1);
	if (!pid)
	{
		if (signal(SIGINT, &heredoc_handler) == SIG_ERR)
			perror("SIGQUIT Error");
		heredoc_child(shell, name, fd);
	}
	else
	{
		if (signal(SIGINT, SIG_IGN) == SIG_ERR)
			perror("SIGQUIT Error");
		waitpid(pid, &shell->exit_code, 0);
		shell->exit_code = WEXITSTATUS(shell->exit_code);
		if (heredoc_parent(shell, fd) < 0)
			return (-1);
		check_signal(shell);
	}
	return (0);
}
