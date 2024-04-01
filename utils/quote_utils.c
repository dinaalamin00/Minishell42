/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:54:19 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/01 15:54:22 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	close_quote(char **str, char symbol)
{
	char	*temp;
	int		i;

	temp = malloc (ft_strlen(*str) + 2);
	if (!temp)
		return ;
	i = 0;
	while ((*str)[i])
	{
		temp[i] = (*str)[i];
		i++;
	}
	temp[i++] = symbol;
	temp[i] = '\0';
	free(*str);
	*str = temp;
}
