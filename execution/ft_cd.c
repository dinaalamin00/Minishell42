/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:37:04 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/21 14:29:07 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_cd(t_mshell *shell)
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
			return (ft_putendl_fd("cd: HOME not set", 2), 1);
	}
	else
		directory = shell->command[1];
	getcwd(pwd, sizeof(pwd));
	if (chdir(directory) < 0)
		return (perror("cd"), 1);
	if (!add_var(shell, ft_str_join("OLDPWD=", pwd)))
		return (malloc_error(shell, 0, -1), 1);
	if (!add_var(shell, ft_str_join("PWD=", getcwd(pwd, sizeof(pwd)))))
		return (malloc_error(shell, 0, -1), 1);
	return (0);
}
