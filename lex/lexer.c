/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:59:19 by mafaisal          #+#    #+#             */
/*   Updated: 2024/03/25 13:49:38 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	lexer(t_mshell *shell)
{
	quote_validity(shell->user_input);
	redirect_validity(shell->user_input);
	split_by_quote(shell);
	split_by_redirect(shell);
	for(int i =0; shell->tokens[i]; i++)
		printf("(%s)\n", shell->tokens[i]);
}
