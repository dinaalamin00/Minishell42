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


// char	*str_pipe(const char *str)
// {
// 	int		i;
// 	char	symbol;

// 	i = 0;
// 	if (!str)
// 		return (NULL);
// 	while (str[i])
// 	{
// 		if (str[i] == '|')
// 			return ((char *)str + i);
// 		if (str[i] == '\'' || str[i] == '\"')
// 		{
// 			symbol = str[i++];
// 			while (str[i] != symbol && str[i])
// 				i++;
// 		}
// 		else
// 			i++;
// 	}
// 	return (NULL);
// }

int	skip_quote(char *str, int i)
{
	char	symbol;

	symbol = str[i++];
	while (str[i] != symbol && str[i])
		i++;
	if (str[i] == symbol)
		i++;
	return (i);
}

// int	cmd_counter(char *user_input)
// {
// 	int	i;
// 	int	cnt;

// 	i = 0;
// 	cnt = 0;
// 	while (user_input && str_pipe(user_input))
// 	{
// 		cnt++;
// 		user_input = str_pipe(user_input) + 1;
// 	}
// 	cnt++;
// 	return (cnt);
// }


char	**split_by_pipe(t_mshell *shell)
{
	int		i;
	int		j;

	shell->pipe_command = ft_calloc(1, sizeof(char *));
	if (!shell->pipe_command)
		malloc_error(shell, 0, -1);
	i = 0;
	// shell->pipe_command[0] = NULL;
	while (shell->user_input[i] != '\0')
	{
		j = i;
		while (shell->user_input[i] != '|' && !is_quote(shell->user_input[i])
			&& shell->user_input[i])
			i++;
		if (is_quote(shell->user_input[i]))
			i = skip_quote(shell->user_input, i);
		if (shell->user_input[i] == '|' || !shell->user_input[i])
		{
			shell->pipe_command = append_to_array(shell, shell->pipe_command,
				ft_substr(shell->user_input, j, i - j));
		}
		if (shell->user_input[i])
			i++;
	}
	for(int k=0;shell->pipe_command[k];k++)
		printf("cmd : (%s)\n", shell->pipe_command[k]);
	return(shell->pipe_command);
}