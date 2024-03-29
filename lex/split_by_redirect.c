/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_redirect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:45:50 by diahmed           #+#    #+#             */
/*   Updated: 2024/03/29 11:14:07 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


char	*copy_symbols(char	*str)
{
	int		i;
	char	*dest;

	i = 0;
	while ((str[i] == '<' || str[i] == '>') && (str[i]))
		i++;
	dest = malloc ((i + 1) * sizeof (char ));
	if (!dest)
		return (NULL);
	i = 0;
	while ((str[i] == '<' || str[i] == '>') && (str[i]))
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**split_string(char **array, char *str)
{
	char	*temp;

	while (str && *str)
	{
		if (!(*str == '<' || *str == '>'))
			array = append_to_array(array, ft_strccpy(str, "<>"));
		str = ft_strset(str, "<>");
		if (!str)
			break ;
		array = append_to_array(array, copy_symbols(str));
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
		return ;
	new_tokens[0] = NULL;
	while (shell->tokens[i])
	{
		if (!ft_strset(shell->tokens[i], "\"\'"))
		{
			if (ft_strset(shell->tokens[i], "<>"))
			{
				new_tokens = split_string(new_tokens, shell->tokens[i++]);
				if (!new_tokens)
					return ;
				continue ;
			}
		}
		new_tokens = append_to_array(new_tokens,
				ft_strccpy(shell->tokens[i++], "<>"));
	}
	ft_free(shell->tokens);
	shell->tokens = new_tokens;
}
