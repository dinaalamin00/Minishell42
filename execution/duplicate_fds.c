/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_fds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:32:47 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/01 15:11:57 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// static int	here_doc(char *delimiter)
// {

// }
static void	open_file(t_mshell *shell)
{
	t_flist	*file;

	file = shell->stdfile;
	while (file)
	{
		if (file->mode == RD)
			file->fd = open(file->name, O_RDONLY, 0644);
		// else if (file->mode == HERE_DOC)
		// 	file->fd = here_doc(file->name);
		else if (file->mode == WR)
			file->fd = open(file->name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		else if (file->mode == APPEND)
			file->fd = open(file->name, O_CREAT | O_WRONLY | O_APPEND, 0644);
		else if (file->mode == RDWR)
			file->fd = open(file->name, O_CREAT | O_RDWR, 0644);
		if (file->fd < 0)
			perror(file->name);
		file = file->next;
	}
	shell->stdfile = file;
}
void	open_dup(t_mshell *shell)
{
	t_flist	*file;

	open_file(shell);
	file = shell->stdfile;
	while (file)
	{
		if (file->mode == RD || file->mode == HERE_DOC)
		{
			if (dup2(file->fd, STDIN_FILENO) < 0)
				perror("Error duplicating fd");
		}
		else if (file->mode == 1 || file->mode == 2)
		{
			if (dup2(file->fd, STDOUT_FILENO) < 0)
				perror("Error duplicsitng fd");
		}
		close (file->fd);
		file = file->next;
	}
	flst_clear(&shell->stdfile);
}
