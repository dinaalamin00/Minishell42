/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:44:27 by diahmed           #+#    #+#             */
/*   Updated: 2024/05/03 15:54:53 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	skip_quote(char *str, int i)
{
	char	symbol;

	symbol = str[i++];
	while (str[i] != symbol && str[i])
		i++;
	if (str[i] == symbol)
		i++;
	return (i);
}

char	**split_by_pipe(t_mshell *shell)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (shell->user_input[i] != '\0')
	{
		while (shell->user_input[i] != '|' && !is_quote(shell->user_input[i])
			&& shell->user_input[i])
			i++;
		if (is_quote(shell->user_input[i]))
			i = skip_quote(shell->user_input, i);
		if (shell->user_input[i] == '|' || shell->user_input[i] == '\0')
		{
			shell->pipe_command = append_to_array(shell, shell->pipe_command,
					ft_substr(shell->user_input, j, i - j));
			j = i + 1;
			if (!shell->user_input[i])
				break ;
		}
		if (!is_quote(shell->user_input[i]))
			i++;
	}
	return (shell->pipe_command);
}
