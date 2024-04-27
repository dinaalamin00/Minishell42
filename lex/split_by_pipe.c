/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:44:27 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/27 18:04:07 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


char	*str_pipe(const char *str)
{
	int		i;
	char	symbol;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '|')
			return ((char *)str + i);
		if (str[i] == '\'' || str[i] == '\"')
		{
			symbol = str[i++];
			while (str[i] != symbol && str[i])
				i++;
		}
		else
			i++;
	}
	return (NULL);
}

int	cmd_counter(char *user_input)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (user_input && str_pipe(user_input))
	{
		cnt++;
		user_input = str_pipe(user_input) + 1;
	}
	cnt++;
	return (cnt);
}


char	**split_by_pipe(t_mshell *shell)
{
	int		i;
	int		j;
	int		k;
	char	**pipe_cmd;

	pipe_cmd = malloc((cmd_counter(shell->user_input) + 1) * sizeof(char *));
	if (!pipe_cmd)
		malloc_error(shell, 0, -1);
	i = 0;
	while (shell->user_input[i])
	{
		j = i;
		while (ft_Str)
	}
}