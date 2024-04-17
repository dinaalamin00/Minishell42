/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_qoute.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:37:34 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/17 16:15:10 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_quote(char c)
{
	if ((c == '\"') || (c == '\''))
		return (1);
	return (0);
}

static char	*copy_quoted_str(char *user_input, int *i)
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
	{
		while (!is_quote(user_input[*i])
			&& user_input[*i])
		{
			if (user_input[*i] == 32 && is_quote(user_input[*i + 1]))
				break ;
			(*i)++;
		}
	}
	token = ft_substr(user_input, start, (*i) - start);
	return (token);
}

static int	token_counter(char *user_input)
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
		ft_putendl_fd("Malloc error! Free up some space", 2);
		free_shell(shell, 0, -1);
	}
	i = 0;
	j = 0;
	while (shell->user_input[i])
	{
		tokens[j] = copy_quoted_str(shell->user_input, &i);
		if (!tokens[j])
		{
			ft_putendl_fd("Malloc error! Free up some space", 2);
			free_shell(shell, 0, -1);
			return ;
		}
		j++;
	}
	tokens[j] = NULL;
	shell->tokens = tokens;
}
