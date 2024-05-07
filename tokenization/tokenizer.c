/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:59:19 by mafaisal          #+#    #+#             */
/*   Updated: 2024/05/04 10:27:20 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	tokenizer(t_mshell *shell)
{
	if (!quote_validity(shell))
		return (EXIT_FAILURE);
	if (!split_by_quote(shell))
		return (EXIT_FAILURE);
	if (!split_by_redirect(shell))
		return (EXIT_FAILURE);
	if (!split_by_space(shell))
		return (EXIT_FAILURE);
	if (!redirect_validity(shell))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
