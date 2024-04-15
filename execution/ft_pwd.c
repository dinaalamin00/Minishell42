/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:21:59 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/15 15:39:50 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_pwd(t_mshell *shell)
{
	char	cwd[PATH_MAX];

	if ((ft_strncmp(shell->command[0], "pwd", 4))
		&& array_len(shell->command) > 1)
	{
		ft_putendl_fd("usage: pwd [without options]", 2);
		//free_shell
		return ;
	}
	if (getcwd(cwd, sizeof(cwd)))
		printf("%s\n", cwd);
	else
		perror("PWD ERROR");
}
