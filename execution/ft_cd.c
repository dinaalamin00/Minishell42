/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:37:04 by diahmed           #+#    #+#             */
/*   Updated: 2024/05/03 18:05:44 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_directory(t_mshell *shell)
{
	char	*directory;
	t_param	*home;

	if (!shell->command[1])
	{
		home = get_param(shell->params, "HOME");
		if (home)
			directory = home->value;
		else
			return (ft_putendl_fd("cd: HOME not set", 2), NULL);
	}
	else
		directory = shell->command[1];
	return (directory);
}

int	ft_cd(t_mshell *shell)
{
	char	*directory;
	char	pwd[PATH_MAX];
	char	*oldpwd;
	char	*cpwd;

	directory = get_directory(shell);
	if (!directory)
		return (1);
	getcwd(pwd, sizeof(pwd));
	if (chdir(directory) < 0)
		return (perror("cd"), 1);
	oldpwd = ft_str_join("OLDPWD=", pwd);
	if (!add_var(shell, oldpwd))
		return (free(oldpwd), malloc_error(shell, 0, -1), 1);
	cpwd = ft_str_join("PWD=", getcwd(pwd, sizeof(pwd)));
	if (!add_var(shell, cpwd))
		return (free(oldpwd), free(cpwd), malloc_error(shell, 0, -1), 1);
	return (free(oldpwd), free(cpwd), 0);
}
// FREE STRING WHEN ADD VAR FAILS
