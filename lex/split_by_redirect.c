/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_redirect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:45:50 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/17 19:01:27 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*copy_symbols(char	*str)
{
	int		i;
	char	*dest;

	i = 0;
	while (is_redirect(str[i]) && (str[i]))
		i++;
	dest = malloc ((i + 1) * sizeof (char ));
	if (!dest)
		return (NULL);
	i = 0;
	while (is_redirect(str[i]) && (str[i]))
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**split_string(t_mshell *shell, char **array, char *str)
{
	char	*temp;

	while (str && *str)
	{
		if (!(*str == '<' || *str == '>'))
			array = append_to_array(shell, array, ft_strccpy(str, "<>"));
		str = ft_strset(str, "<>");
		if (!str)
			break ;
		array = append_to_array(shell, array, copy_symbols(str));
		temp = copy_symbols(str);
		str = str + ft_strlen(temp);
		free(temp);
	}
	return (array);
}

void	split_by_redirect(t_mshell *shell)
{
	char	**new_tokens;
	int		i;

	i = 0;
	new_tokens = malloc (1 * sizeof (char *));
	if (!new_tokens)
	{
		ft_putendl_fd("Malloc error! Free up some space", 2);
		free_shell(shell, 0, -1);
		return ;
	}
	new_tokens[0] = NULL;
	while (shell->tokens[i])
	{
		if (!ft_strset(shell->tokens[i], "\"\'"))
		{
			if (ft_strset(shell->tokens[i], "<>"))
			{
				new_tokens = split_string(shell, new_tokens, shell->tokens[i++]);
				if (!new_tokens)
				{
					ft_putendl_fd("Malloc error! Free up some space", 2);
					free_shell(shell, 0, -1);
					return ;
				}
				continue ;
			}
		}
		new_tokens = append_to_array(shell, new_tokens,
				ft_strdup(shell->tokens[i++]));
	}
	if (shell->tokens)
		ft_free(shell->tokens);
	shell->tokens = new_tokens;
}
