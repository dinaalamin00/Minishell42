/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_validity.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:35:10 by diahmed           #+#    #+#             */
/*   Updated: 2024/03/22 15:35:31 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//- checks that each consecutive redirections should be less than 3
//- each redirect should not be followed by null

static int	valid_redirect(char *user_input)
{
	int		cnt;
	char	symbol;
	char	*trimmed_input;
	char	*temp;

	cnt = 0;
	trimmed_input = ft_strtrim(user_input, " \t");
	temp = trimmed_input;
	while (trimmed_input && ft_strset(trimmed_input, "<>"))
	{
		trimmed_input = ft_strset(trimmed_input, "<>");
		symbol = *trimmed_input;
		while (symbol == *trimmed_input)
		{
			cnt++;
			trimmed_input++;
		}
		if (cnt > 2 || *trimmed_input == '\0'
			||(symbol == '>' && *trimmed_input == '<'))
		{
			free(temp);
			return (0);
		}
	}
	free(temp);
	return (1);
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
