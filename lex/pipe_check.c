/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_lex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:10:19 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/27 17:10:28 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*str_pipe(const char *str)
{
	int		i;
	char	symbol;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '|')
			return ((char *)str + i);
		if (str[i] == '\'' || str[i] == '\"')
		{
			symbol = str[i++];
			while (str[i] != symbol && str[i])
				i++;
		}
		i++;
	}
	return (NULL);
}

int    pipe_check(t_mshell *shell)
{
	if (!quote_validity(shell) || !pipe_validity(shell))
		return (EXIT_FAILURE);
	shell->pipe_command = malloc(1 * sizeof(char *));
	if (!shell->pipe_command)
		malloc_error(shell, 0, -1);
	shell->pipe_command[0] = NULL;
    if (str_pipe(shell->user_input))
	    split_by_pipe(shell);
	else
		shell->pipe_command = append_to_array(shell, shell->pipe_command,
			ft_strdup(shell->user_input));
	for(int k=0;shell->pipe_command[k];k++)
		printf("cmd : (%s)\n", shell->pipe_command[k]);
	return (0);
}
