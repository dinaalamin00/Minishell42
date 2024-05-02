/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_fds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:32:47 by diahmed           #+#    #+#             */
/*   Updated: 2024/05/01 15:16:34 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	open_file(t_mshell *shell, int *error)
{
	t_flist	*file;

	file = shell->stdfile;
	while (file)
	{
		if (file->mode == RD)
			file->fd = open(file->name, O_RDONLY, 0644);
		else if (file->mode == HERE_DOC)
			here_doc(shell, file->name);
		else if (file->mode == WR && shell->file_err != 1)
			file->fd = open(file->name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		else if (file->mode == APPEND && shell->file_err != 1)
			file->fd = open(file->name, O_CREAT | O_WRONLY | O_APPEND, 0644);
		else if (file->mode == RDWR && shell->file_err != 1)
			file->fd = open(file->name, O_CREAT | O_RDWR, 0644);
		if (file->fd == -1 && file->mode != HERE_DOC)
		{
			perror(file->name);
			shell->exit_code = 1;
			*error = 1;
			if (file->mode == RD || file->mode == RDWR)
				shell->file_err = 1;
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
		if (file->mode == RD)
			dup_status = dup2(file->fd, STDIN_FILENO);
		else if (file->mode == WR || file->mode == 2)
			dup_status = dup2(file->fd, STDOUT_FILENO);
		if (file->fd >= 0 && dup_status < 0)
		{
			perror("Error duplicating fd");
			shell->exit_code = 1;
			error = 1;
		}
		if (file->mode != HERE_DOC)
			close (file->fd);
		file = file->next;
	}
	if (error)
		return (flst_clear(&shell->stdfile), FAILURE);
	return (flst_clear(&shell->stdfile), SUCCESS);
}

void	reset_fds(t_mshell *shell)
{
	if (dup2(shell->orig_stdout, STDOUT_FILENO) < 0
		|| dup2(shell->orig_stdin, STDIN_FILENO) < 0)
		perror("reset fd");
	close (shell->orig_stdin);
	close (shell->orig_stdout);
}
