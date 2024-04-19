/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:15:48 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/19 15:19:48 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	valid_quotes(char *user_input)
{
	int		i;

	i = 0;
	while (user_input[i] && user_input)
	{
		if (user_input[i] == '\"')
		{
			i++;
			while (user_input[i] != '\"' && user_input[i])
				i++;
		}
		else if (user_input[i] == '\'')
		{
			i++;
			while (user_input[i] != '\'' && user_input[i])
				i++;
		}
		if (user_input[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}

bool	quote_validity(t_mshell *shell)
{
	if (ft_strset(shell->user_input, "\"\'"))
	{
		if (!valid_quotes(shell->user_input))
		{
			ft_putendl_fd("Error, unclosed quotes", 2);
			free_shell(shell, 0, -1);
			return (FAILURE);
		}
	}
	return (SUCCESS);
}
