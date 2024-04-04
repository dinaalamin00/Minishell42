/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:59:19 by mafaisal          #+#    #+#             */
/*   Updated: 2024/03/29 18:03:59 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	lexer(t_mshell *shell)
{
	// quote_validity(shell->user_input);
	split_by_quote(shell);
	free(shell->user_input);
	split_by_redirect(shell);
	split_by_space(shell);
	redirect_validity(shell);
}
