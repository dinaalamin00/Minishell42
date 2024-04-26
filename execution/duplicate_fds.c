/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_fds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:32:47 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/26 12:20:32 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	here_doc(t_mshell *shell, char *name)
{
	int		fd[2];
	char	*line;
	char	*delimiter;

	if (pipe(fd) < 0)
		return (ft_putendl_fd("Error creating pipe", 2), -1);
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
	return (fd[0]);
}

static void	open_file(t_mshell *shell, int *error)
{
	t_flist	*file;

	file = shell->stdfile;
	while (file)
	{
		if (file->mode == RD)
			file->fd = open(file->name, O_RDONLY, 0644);
		else if (file->mode == HERE_DOC)
			file->fd = here_doc(shell, file->name);
		else if (file->mode == WR)
			file->fd = open(file->name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		else if (file->mode == APPEND)
			file->fd = open(file->name, O_CREAT | O_WRONLY | O_APPEND, 0644);
		else if (file->mode == RDWR)
			file->fd = open(file->name, O_CREAT | O_RDWR, 0644);
		if (file->fd < 0)
		{
			perror(file->name);
			shell->exit_code = 1;
			*error = 1;
		}
		file = file->next;
	}
}

bool	open_dup(t_mshell *shell)
{
	t_flist	*file;
	int		dup_status;
	int		error;

	error = 0;
	open_file(shell, &error);
	file = shell->stdfile;
	while (file)
	{
		if (file->mode == RD || file->mode == HERE_DOC)
			dup_status = dup2(file->fd, STDIN_FILENO);
		else if (file->mode == 1 || file->mode == 2)
			dup_status = dup2(file->fd, STDOUT_FILENO);
		if (file->fd >= 0 && dup_status < 0)
		{
			perror("Error duplicating fd");
			shell->exit_code = 1;
			error = 1;
		}
		close (file->fd);
		file = file->next;
	}
	if (error)
		return (flst_clear(&shell->stdfile), FAILURE);
	return (flst_clear(&shell->stdfile), SUCCESS);
}

void	reset_fds(t_mshell *shell)
{
	if (dup2(shell->orig_stdout, STDOUT_FILENO))
		dup2(shell->orig_stdin, STDIN_FILENO);
	close (shell->orig_stdout);
	close (shell->orig_stdin);
}
