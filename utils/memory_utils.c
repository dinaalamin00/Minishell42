/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 08:17:40 by mafaisal          #+#    #+#             */
/*   Updated: 2024/05/05 09:56:45 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_shell(t_mshell *shell, int param_flag, int exit_flag)
{
	if (shell->pipe_command)
		ft_free(shell->pipe_command);
	if (shell->tokens)
		ft_free(shell->tokens);
	if (shell->command)
		ft_free(shell->command);
	if (shell->stdfile)
		flst_clear(&(shell->stdfile));
	shell->pipe_command = NULL;
	shell->tokens = NULL;
	shell->command = NULL;
	shell->stdfile = NULL;
	if (shell->params && param_flag)
	{
		free_params(shell->params);
		shell->params = NULL;
	}
	if (exit_flag >= 0)
	{
		rl_clear_history();
		(close(shell->orig_stdin), close(shell->orig_stdout));
		(close(0), close(1), close(2), exit(exit_flag));
	}
}

void	free_params(t_param *params)
{
	t_param	*temp;

	temp = params;
	while (params)
	{
		temp = temp->next;
		free(params->key);
		free(params->value);
		free(params);
		params = temp;
	}
}

void	flst_clear(t_flist **lst)
{
	t_flist	*temp;

	temp = *lst;
	while (*lst)
	{
		temp = (*lst)-> next;
		free((*lst)->name);
		free((*lst));
		*lst = temp;
	}
	*lst = NULL;
}
