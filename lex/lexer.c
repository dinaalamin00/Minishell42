/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:59:19 by mafaisal          #+#    #+#             */
/*   Updated: 2024/04/19 15:42:50 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	lexer(t_mshell *shell)
{
	if (!quote_validity(shell))
		return (FAILURE);
	if (!split_by_quote(shell))
		return (FAILURE);
	free(shell->user_input);
	shell->user_input = NULL;
	if (!split_by_redirect(shell))
		return (FAILURE);
	if (!split_by_space(shell))
		return (FAILURE);
	if (!redirect_validity(shell))
		return (FAILURE);
	return (SUCCESS);
}
