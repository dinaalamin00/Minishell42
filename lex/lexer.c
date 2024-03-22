/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:59:19 by mafaisal          #+#    #+#             */
/*   Updated: 2024/03/22 18:14:00 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	lexer(t_mshell *shell)
{
	quote_validity(shell->user_input);
	redirect_validity(shell->user_input);
	split_by_quote(shell);
	//split_by_redirect(shell);
}
