/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:54:19 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/26 17:16:38 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	close_quote(char **str, char *next_str)
{
	char	*temp;

	if (ft_strset(next_str, "\'\""))
	{
		temp = ft_strdup("\"");
		if (!temp)
			return (FAILURE);
		temp = ft_strjoin(temp, *str);
		if (!temp)
			return (FAILURE);
		temp = ft_strjoin(temp, "\"");
		if (!temp)
			return (FAILURE);
		free(*str);
		*str = temp;
	}
	return (SUCCESS);
}
