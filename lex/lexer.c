/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:59:19 by mafaisal          #+#    #+#             */
/*   Updated: 2024/04/25 07:50:01 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	lexer(t_mshell *shell)
{
	if (!quote_validity(shell))
		return (EXIT_FAILURE);
	if (!split_by_quote(shell))
		return (EXIT_FAILURE);
	free(shell->user_input);
	shell->user_input = NULL;
	if (!split_by_redirect(shell))
		return (EXIT_FAILURE);
	if (!split_by_space(shell))
		return (EXIT_FAILURE);
	if (!redirect_validity(shell))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
