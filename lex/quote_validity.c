/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:15:48 by diahmed           #+#    #+#             */
/*   Updated: 2024/03/22 15:31:00 by diahmed          ###   ########.fr       */
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

void	quote_validity(char *user_input)
{
	if (ft_strset(user_input, "\"\'"))
	{
		if (!valid_quotes(user_input))
		{
			ft_putendl_fd("Error, unclosed quotes", 2);
			free(user_input);
			exit(EXIT_FAILURE);
		}
	}
}
