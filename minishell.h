/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:59:15 by diahmed           #+#    #+#             */
/*   Updated: 2024/03/29 11:30:39 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <fcntl.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"

typedef struct s_flist
{
	char			*name;
	int				fd;
	int				mode;
	struct s_flist	*next;
}	t_flist;

typedef struct s_param
{
	char			*key;
	char			*value;
	int				export;
	struct s_param	*next;
}	t_param;

typedef struct s_mshell
{
	char	*user_input;
	char	**command;
	char	**tokens;
	t_flist	*stdfile;
	t_param	*params;
	int		here_doc_flag;
	int		pipe_exit;
}	t_mshell;

void	run_command(t_mshell *shell, char **env);

//lexer
void	lexer(t_mshell *shell);
//parser
void	parser(t_mshell *shell);
void	expand_params(t_mshell *shell);

//executor

//utils
void	env_to_list(t_mshell *shell, char **env);
t_param	*get_param(t_param *params, char *key);
void	add_var(t_param **param, char *key, char *value);
void	free_params(t_param *params);

#endif
