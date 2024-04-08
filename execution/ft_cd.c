// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_cd.c                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/04/08 15:37:04 by diahmed           #+#    #+#             */
// /*   Updated: 2024/04/08 16:00:18 by diahmed          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../minishell.h"

// void	ft_cd(t_mshell *shell)
// {
// 	char	*directory;
// 	char	pwd[PATH_MAX];

// 	if (!shell->command[1])
// 	{
// 		directory = getenv("HOME");
// 		if (!directory)
// 		{
// 			ft_putendl_fd("cd: HOME not set", 2);
// 			// ft_free(shell->command);
// 			return ;
// 		}
// 	}
// 	else
// 		directory = shell->command[1];
// 	getcwd(pwd, sizeof(pwd));
// 	add_var(&shell->params, "OLDPWD", ft_strdup(pwd));
// 	if (chdir(directory) < 0)
// 		perror("cd");
// 	getcwd(pwd, sizeof(pwd));
// 	add_var(&shell->params, "PWD", ft_strdup(pwd));
// 	// ft_free(shell->command);
// }
