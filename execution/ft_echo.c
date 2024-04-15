/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:39:28 by mafaisal          #+#    #+#             */
/*   Updated: 2024/04/15 15:47:02 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_echo(t_mshell *shell)
{
	int	i;
	int	n;

	i = 1;
	n = 1;
	if (shell->command[1])
		n = ft_strncmp(shell->command[1], "-n", 3);
	if (n == 0)
		i = 2;
	while (shell->command[i] != NULL)
	{
		printf("%s", shell->command[i]);
		if (shell->command[i + 1])
			printf(" ");
		i++;
	}
	if (n != 0)
		printf("\n");
}
