/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_validity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:10:34 by diahmed           #+#    #+#             */
/*   Updated: 2024/05/04 13:03:15 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	valid_pipe(char *str)
{
	int		i;

	i = 0;
	if (str[0] == '|')
		return (FAILURE);
	while (str_pipe(str))
	{
		i = 0;
		str = str_pipe(str) + 1;
		while (str[i] == 32 && str[i])
			i++;
		if (!str[i] || str[i] == '|')
			return (FAILURE);
	}
	return (SUCCESS);
}

bool	pipe_validity(t_mshell *shell)
{
	char	*temp;

	temp = ft_strtrim(shell->user_input, " ");
	if (!valid_pipe(temp))
	{
		free(temp);
		ft_putendl_fd("syntax error near unexpected token `|\'", 2);
		free_shell(shell, 0, -1);
		return (FAILURE);
	}
	free(temp);
	return (SUCCESS);
}
