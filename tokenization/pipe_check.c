/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:10:19 by diahmed           #+#    #+#             */
/*   Updated: 2024/05/05 10:49:03 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	char	last_char(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	if (str[i] == '\0')
	{
		i--;
		return (str[i]);
	}
	return (-1);
}

static void	close_pipe(t_mshell *shell, char *temp)
{
	char	*str;

	if (last_char(temp) == '|')
	{
		while (last_char(temp) == '|')
		{
			str = get_next_line(0);
			if (!str)
			{
				free(temp);
				return ;
			}
			if (*str && *str != '\n')
			{
				str = custom_trim(str, '\n', 2);
				temp = ft_strjoin(temp, str);
			}
			free(str);
			temp = custom_trim(temp, 32, 2);
		}
		free(shell->user_input);
		shell->user_input = temp;
	}
	else
		free(temp);
}

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
		i++;
	}
	return (NULL);
}

int	pipe_check(t_mshell *shell)
{
	close_pipe(shell, ft_strtrim(shell->user_input, " "));
	if (!quote_validity(shell) || !pipe_validity(shell))
		return (EXIT_FAILURE);
	shell->pipe_command = malloc(1 * sizeof(char *));
	if (!shell->pipe_command)
		return (malloc_error(shell, 0, -1), EXIT_FAILURE);
	shell->pipe_command[0] = NULL;
	if (str_pipe(shell->user_input))
		split_by_pipe(shell);
	else
		shell->pipe_command = append_to_array(shell, shell->pipe_command,
				ft_strdup(shell->user_input));
	free(shell->user_input);
	shell->user_input = NULL;
	return (EXIT_SUCCESS);
}
