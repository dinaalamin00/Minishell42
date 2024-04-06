/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:59:59 by mafaisal          #+#    #+#             */
/*   Updated: 2024/04/06 17:14:28 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	executor(t_mshell *shell, char **env)
{
	(void)env;
	open_dup(shell);
	free_params(shell->params);
	ft_free(shell->command);
}
