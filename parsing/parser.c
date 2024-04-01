/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:58:47 by mafaisal          #+#    #+#             */
/*   Updated: 2024/04/01 16:11:35 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parser(t_mshell *shell, char **env)
{
	env_to_list(shell, env);
	expand_params(shell);
	parse_files(shell);
	clean_command(shell);
}
