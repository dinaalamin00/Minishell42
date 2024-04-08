/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:48:47 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/08 13:44:07 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_shell(t_mshell *shell)
{
	(void)shell;
	//free_param
	//free_token
	//free_command
	//free_user_input
	//free_files
}

void    key_error(char *cmd, char *key)
{
    ft_putstr_fd(cmd, 2);
    ft_putstr_fd(": `", 2);
    ft_putstr_fd(key, 2);
    ft_putstr_fd("\': not a valid identifier", 2);
}
