/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_validity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:10:34 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/29 11:27:56 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	valid_pipe(char *str)
{
	int		i;
	char	*temp;

	i = 0;
	temp = str;
	if (str[0] == '|')
	{
		free(temp);
		return (0);
	}
	while (str_pipe(str))
	{
		i = 0;
		str = str_pipe(str) + 1;
		while (str[i] == 32 && str[i])
			i++;
		if (!str[i] || str[i] == '|')
		{
			free(temp);
			return (0);
		}
	}
	free(temp);
	return (1);
}

bool	pipe_validity(t_mshell *shell)
{
	char	*temp;

	temp = ft_strtrim(shell->user_input, " ");
	if (!valid_pipe(temp))
	{
		ft_putendl_fd("syntax error near unexpected token `|\'", 2);
		free_shell(shell, 0, -1);
		return (FAILURE);
	}
	return (SUCCESS);
}
