/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:33:14 by mafaisal          #+#    #+#             */
/*   Updated: 2024/03/29 11:11:07 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	run_command(t_mshell *shell, char **env)
{
	lexer(shell);
	// parser(shell); 
	// check_files(shell);
	// open_dup(shell);
	// refactor_command(shell);
	// executor(shell, env);
}
