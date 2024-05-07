/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_initialization.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:09:59 by mafaisal          #+#    #+#             */
/*   Updated: 2024/05/05 12:03:03 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	env_to_list(t_mshell *shell, char **env)
{
	int	i;

	i = 0;
	while (env && env[i])
	{
		if (!add_var(shell, env[i]))
			return (malloc_error(shell, 1, -1), FAILURE);
		i++;
	}
	return (SUCCESS);
}

bool	update_shlvl(t_mshell *shell)
{
	char	*level;
	t_param	*shlvl;

	shlvl = get_param(shell->params, "SHLVL");
	if (shlvl)
	{
		level = shlvl->value;
		if (level && is_alldigit(level))
			(shlvl->value = ft_itoa(ft_atoi(level) + 1));
		else if (level && *level == '-' && is_alldigit(level + 1))
			(shlvl->value = ft_strdup("0"));
		else if (!level || !is_alldigit(level))
			(shlvl->value = ft_strdup("1"));
		free(level);
		if (!shlvl->value)
			return (malloc_error(shell, 0, -1), FAILURE);
	}
	else
	{
		if (!add_var(shell, "SHLVL=1"))
			return (malloc_error(shell, 0, -1), FAILURE);
	}
	return (SUCCESS);
}

void	set_path(t_mshell *shell)
{
	t_param	*path;

	path = get_param(shell->params, "PATH");
	if (!path)
		add_var(shell, "PATH=/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin");
}

void	set_pwd(t_mshell *shell)
{
	char	cwd[PATH_MAX];
	char	*pwd;

	if (getcwd(cwd, sizeof(cwd)))
	{
		pwd = ft_str_join("PWD=", cwd);
		if (!add_var(shell, pwd))
			malloc_error(shell, 0, -1);
		free(pwd);
	}
	else
		perror("PWD ERROR");
}

t_mshell	init_shell(char **envp)
{
	t_mshell	shell;

	ft_bzero(&shell, sizeof(t_mshell));
	env_to_list(&shell, envp);
	update_shlvl(&shell);
	set_path(&shell);
	set_pwd(&shell);
	(&shell)->orig_stdin = dup(STDIN_FILENO);
	(&shell)->orig_stdout = dup(STDOUT_FILENO);
	return (shell);
}
