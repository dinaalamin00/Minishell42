/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_qoute.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:37:34 by diahmed           #+#    #+#             */
/*   Updated: 2024/03/22 18:15:45 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
	this function splits the comand by quotes,
	if there is ant spaces after or before the quotes it will be put in the quotes string,
		for the normal strings it will not contain any quotes
*/
int	is_quote(char c)
{
	if ((c == '\"') || (c == '\''))
		return (1);
	return (0);
}

char	*copy_quoted_str(char *user_input, int *i)
{
	int		start;
	char	symbol;
	char	*token;

	start = *i;
	while (user_input[*i] == 32)
		(*i)++;
	if (is_quote(user_input[*i]))
	{
		symbol = user_input[(*i)++];
		while (symbol != user_input[*i] && user_input[*i])
			(*i)++;
		(*i)++;
		while (user_input[*i] == 32)
			(*i)++;
	}
	else
		while (!is_quote(user_input[*i])
			&& user_input[*i] && user_input[*i] != 32)
			(*i)++;
	token = ft_substr(user_input, start, (*i) - start);
	return (token);
}

int	token_counter(char *user_input)
{
	int		i;
	int		cnt;
	char	symbol;

	i = 0;
	cnt = 0;
	while (user_input[i])
	{
		cnt++;
		if (is_quote(user_input[i]))
		{
			symbol = user_input[i];
			i++;
			while (symbol != user_input[i] && user_input[i])
				i++;
			i++;
		}
		else
		{
			while (!is_quote(user_input[i]) && user_input[i])
				i++;
		}
	}
	return (cnt);
}

void	split_by_quote(t_mshell *shell)
{
	char	**tokens;
	int		i;
	int		j;

	tokens = malloc((token_counter(shell->user_input) + 1) * sizeof(char *));
	if (!tokens)
	{
		ft_putendl_fd("Error, malloc", 2);
		free(shell->user_input);
		exit (EXIT_FAILURE);
	}
	i = 0;
	j = 0;
	while (shell->user_input[i])
	{
		tokens[j] = copy_quoted_str(shell->user_input, &i);
		if (!tokens[j])
		{
			ft_free(tokens);
			return ;
		}
		j++;
	}
	tokens[j] = NULL;
	shell->tokens = tokens;
}

