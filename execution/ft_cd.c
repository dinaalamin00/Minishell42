/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:37:04 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/08 18:37:30 by mafaisal         ###   ########.fr       */
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
			// ft_free(shell->command);
			return ;
		}
	}
	else
		directory = shell->command[1];
	getcwd(pwd, sizeof(pwd));
	add_var(&shell->params, ft_str_join("OLDPWD=", pwd));
	if (chdir(directory) < 0)
		perror("cd");
	getcwd(pwd, sizeof(directory));
	add_var(&shell->params, ft_str_join("PWD=", pwd));
	// ft_free(shell->command);
}
