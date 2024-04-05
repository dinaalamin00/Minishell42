/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_fds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:32:47 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/05 14:25:39 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	here_doc(char *name)
{
	int		fd[2];
	char	*line;
	char	*delimiter;

	if (pipe(fd) < 0)
	{
		ft_putendl_fd("Error creating pipe", 2);
		return (-1);
	}
	// close(fd[0]);
	line = get_next_line(0);
	delimiter = ft_str_join(name, "\n");
	while (line && ft_strncmp(line, delimiter, ft_strlen(delimiter) + 1) != 0)
	{
		ft_putstr_fd(line, fd[1]);
		free(line);
		line = get_next_line(0);
	}
	free(delimiter);
	free(line);
	close(fd[1]);
	return (fd[0]);
}

static void	open_file(t_mshell *shell)
{
	t_flist	*file;

	file = shell->stdfile;
	while (file)
	{
		if (file->mode == RD)
			file->fd = open(file->name, O_RDONLY, 0644);
		else if (file->mode == HERE_DOC)
		{
			file->fd = here_doc(file->name);
			char *line = get_next_line(file->fd);
			while (line)
			{
				printf("line: %s", line);
				free(line);
				line = get_next_line(file->fd);
			}
		}
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
				perror("Error duplicating fd");
		}
		close (file->fd);
		file = file->next;
	}
	flst_clear(&shell->stdfile);
}
