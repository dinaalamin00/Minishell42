/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_validity.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:35:10 by diahmed           #+#    #+#             */
/*   Updated: 2024/03/29 18:36:33 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//- checks that each consecutive redirections should be less than 3
//- each redirect should not be followed by null

int	is_redirect(char c)
{
	if ((c == '<') || (c == '>'))
		return (1);
	return (0);
}

static int	valid_redirect(char **user_input, int i)
{
	if (ft_strlen(user_input[i]) > 2 || (!user_input[i + 1])
		|| (user_input[i][0] == '>' && user_input[i][1] == '<'))
		return (0);
	return (1);
}

void	redirect_validity(t_mshell *shell)
{
	int		i;
	char	*trimmed_input;
	char	*input_ptr;

	i = 0;
	while (shell->tokens[i])
	{
		if (!ft_strset(shell->tokens[i], "\'\""))
		{
			if (ft_strset(shell->tokens[i], "<>"))
			{
				if (!valid_redirect(shell->tokens, i))
				{
					ft_putendl_fd("syntax error, unexpected token", 2);
					ft_free(shell->tokens);
					exit (EXIT_FAILURE);
				}
			}
		}
		i++;
	}
}
