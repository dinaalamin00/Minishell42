/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:59:19 by mafaisal          #+#    #+#             */
/*   Updated: 2024/04/17 19:07:29 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	lexer(t_mshell *shell)
{
	quote_validity(shell);
	if (!shell->user_input)
		return ;
	split_by_quote(shell);
	free(shell->user_input);
	shell->user_input = NULL;
	if (!shell->tokens)
		return ;
	split_by_redirect(shell);
	if (!shell->tokens)
		return ;
	split_by_space(shell);
	if (!shell->tokens)
		return ;
	redirect_validity(shell);
}
