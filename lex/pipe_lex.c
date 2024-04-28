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
		else
			i++;
	}
	return (NULL);
}

void    pipe_check(t_mshell *shell)
{
    if (str_pipe(shell->user_input))
	    split_by_pipe(shell);
}
