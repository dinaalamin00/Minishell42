/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:58:47 by mafaisal          #+#    #+#             */
/*   Updated: 2024/04/01 15:03:03 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parser(t_mshell *shell, char **env)
{
	env_to_list(shell, env);
	expand_params(shell);
	clean_command(shell);
	exit(0);
}
