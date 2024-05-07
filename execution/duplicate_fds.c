/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_fds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:32:47 by diahmed           #+#    #+#             */
/*   Updated: 2024/05/06 10:13:14 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static bool	open_heredocs(t_mshell *shell)
{
	t_flist	*file;

	file = shell->stdfile;
	while (file)
	{
		if (file->mode == HERE_DOC)
			file->fd = here_doc(shell, file->name);
		if (file->fd == -1)
		{
			shell->exit_code = 1;
			shell->file_err = 1;
			break ;
		}
		file = file->next;
	}
	if (shell->file_err == 1)
		return (FAILURE);
	return (SUCCESS);
}

static bool	open_file(t_mshell *shell)
{
	t_flist	*file;

	file = shell->stdfile;
	while (file && shell->file_err != 1)
	{
		if (file->mode == RD)
			file->fd = open(file->name, O_RDONLY, 0644);
		else if (file->mode == WR)
			file->fd = open(file->name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		else if (file->mode == APPEND)
			file->fd = open(file->name, O_CREAT | O_WRONLY | O_APPEND, 0644);
		else if (file->mode == RDWR)
			file->fd = open(file->name, O_CREAT | O_RDWR, 0644);
		if (file->fd == -1)
		{
			perror(file->name);
			shell->exit_code = 1;
			shell->file_err = 1;
		}
		file = file->next;
	}
	if (shell->file_err == 1)
		return (FAILURE);
	return (SUCCESS);
}

bool	open_dup(t_mshell *shell)
{
	t_flist	*file;
	int		dup_status;

	if (!open_heredocs(shell))
		return (free_shell(shell, 0, -1), FAILURE);
	if (!open_file(shell))
		return (flst_clear(&shell->stdfile), FAILURE);
	file = shell->stdfile;
	while (file)
	{
		if (file->mode == RD)
			dup_status = dup2(file->fd, STDIN_FILENO);
		else if (file->mode == WR || file->mode == APPEND)
			dup_status = dup2(file->fd, STDOUT_FILENO);
		if (file->mode != HERE_DOC && dup_status < 0)
			(perror("Error duplicating fd"),
				shell->exit_code = 1, shell->file_err = 1);
		if (file->mode != HERE_DOC)
			close (file->fd);
		file = file->next;
	}
	if (shell->file_err == 1)
		return (flst_clear(&(shell->stdfile)), FAILURE);
	return (flst_clear(&(shell->stdfile)), SUCCESS);
}

void	reset_fds(t_mshell *shell)
{
	if (dup2(shell->orig_stdin, STDIN_FILENO) < 0)
		perror("reset in fd");
	if (dup2(shell->orig_stdout, STDOUT_FILENO) < 0)
		perror("reset out fd");
}
