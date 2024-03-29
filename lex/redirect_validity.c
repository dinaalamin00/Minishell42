/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_validity.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:35:10 by diahmed           #+#    #+#             */
/*   Updated: 2024/03/29 11:49:27 by diahmed          ###   ########.fr       */
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

static int	valid_redirect(char *user_input)
{
	int		cnt;
	char	symbol;
	char	*trimmed_input;
	char	*temp;

	trimmed_input = ft_strtrim(user_input, " \t");
	temp = trimmed_input;
	while (trimmed_input && ft_strset(trimmed_input, "<>"))
	{
		trimmed_input = ft_strset(trimmed_input, "<>");
		symbol = *trimmed_input;
		cnt = 0;
		while (symbol == trimmed_input[cnt])
			cnt++;
		trimmed_input += cnt;
		if ((cnt > 2) || (*trimmed_input == '\0')
			|| (symbol == '>' && *trimmed_input == '<')
			|| (is_redirect(*trimmed_input) && cnt == 2))
			return (free(temp), 0);
		while (*trimmed_input == 32)
			trimmed_input++;
		if ((is_redirect(*trimmed_input) && *(trimmed_input - 1) == 32))
			return (free(temp), 0);
	}
	return (free(temp), 1);
}

void	redirect_validity(char *user_input)
{
	if (ft_strset(user_input, "<>"))
	{
		if (!valid_redirect(user_input))
		{
			ft_putendl_fd("syntax error, unexpected token", 2);
			free(user_input);
			exit (EXIT_FAILURE);
		}
	}
}
