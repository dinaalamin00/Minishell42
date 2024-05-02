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

int	heredoc_child(t_mshell *shell, char *name, int *fd)
{
	char	*line;
	char	*delimiter;

	if (signal(SIGINT, &heredoc_handler) == SIG_ERR)
			perror("heredoc SIGINT Error");
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
	return(fd[1]);
}

int	heredoc_parent(t_mshell *shell, char *name, int *fd, pid_t pid)
{
	if (signal(SIGINT, SIG_IGN) == SIG_ERR)
		perror("SIGQUIT Error");
	// if (signal(SIGINT, &heredoc_parent) == SIG_ERR)
	// perror("SIGINT Error")
	// ;
	waitpid(pid, &shell->exit_code, 0);
	// shell->exit_code = WEXITSTATUS(shell->exit_code);
	if (WIFSIGNALED(shell->exit_code))
	{
		printf("pernt\n");
		if (WTERMSIG(shell->exit_code) == SIGINT)
			shell->exit_code = 1;
	}
	else
		shell->exit_code = WEXITSTATUS(shell->exit_code);
	printf("exit code = %d\n", shell->exit_code);
	if (shell->exit_code != 0)
	{
		// check_signal(shell);
		// shell->here_flag = 1;
		return (-1);
	}
	else
	{
		if (dup2(fd[0], STDIN_FILENO) < 0)
			perror(NULL);
		// close(fd[0]);
	}
	return(0);
}

int	here_doc(t_mshell *shell, char *name)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) < 0)
		return (perror("pipe error"), -1);
	pid = fork();
	if (pid < 0)
		return (perror("heredoc fork error"), -1);
	if (!pid)
	{
		close(fd[0]);
		fd[1] = heredoc_child(shell, name, fd);
		printf("hrdch\n");
		exit(0);
	}
	else
	{
		close(fd[1]);
		if (heredoc_parent(shell, name, fd, pid) < 0)
		{
			close(fd[0]);
			check_signal(shell);
			return (-1);
		}
		close(fd[0]);
	}
	check_signal(shell);
	return (0);
}
