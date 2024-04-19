/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:19:52 by mafaisal          #+#    #+#             */
/*   Updated: 2024/04/19 09:28:29 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	valid_key(char *key)
{
	int	i;

	if (!ft_isalpha(key[0]) && key[0] != '_')
		return (ft_putendl_fd("not a valid key", 2), 0);
	i = 1;
	while (key[i])
	{
		if (!ft_isdigit(key[i]) && !ft_isalpha(key[i]) && key[i] != '_')
			return (ft_putendl_fd("not a valid key", 2), 0);
		i++;
	}
	return (1);
}

int	valid_value(char *value)
{
	if (!value)
		return (1);
	return (1);
}

void	ft_export(t_mshell *shell)
{
	int		i;
	char	*env_var;

	i = 1;
	if (!shell->command[i])
		ft_env(shell, 1);
	while (shell->command[i])
	{
		add_var(shell, shell->command[i]);
		if (!shell->command)
			return ;
		i++;
	}
}
