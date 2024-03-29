/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:58:47 by mafaisal          #+#    #+#             */
/*   Updated: 2024/03/29 14:05:20 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parser(t_mshell *shell, char **env)
{
	env_to_list(shell, env);
	expand_params(shell);
	exit(0);
	//open_dup(shell);
	//remove_redrections
	//remove_quotes_spaces
}
