/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:37:04 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/15 11:25:04 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_cd(t_mshell *shell)
{
	char	*directory;
	char	pwd[PATH_MAX];
	t_param	*home;

	if (!shell->command[1])
	{
		home = get_param(shell->params, "HOME");
		if (home)
			directory = home->value;
		else
		{
			ft_putendl_fd("cd: HOME not set", 2);
			return ;
		}
	}
	else
		directory = shell->command[1];
	getcwd(pwd, sizeof(pwd));
	if (chdir(directory) < 0)
	{
		perror("cd");
		return ;
	}
	add_var(&shell->params, ft_str_join("OLDPWD=", pwd));
	add_var(&shell->params, ft_str_join("PWD=", getcwd(pwd, sizeof(pwd))));
}
