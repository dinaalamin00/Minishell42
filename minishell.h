/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:59:15 by diahmed           #+#    #+#             */
/*   Updated: 2024/03/29 12:54:36 by mafaisal         ###   ########.fr       */
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
void	quote_validity(char *user_input);
int		is_quote(char c);
void	redirect_validity(char *user_input);
int		is_redirect(char c);
void	split_by_quote(t_mshell *shell);
void	split_by_redirect(t_mshell *shell);
void	split_by_space(t_mshell *shell);

//parser
void	parser(t_mshell *shell, char **env);
void	expand_params(t_mshell *shell);

//executor

//utils
void	env_to_list(t_mshell *shell, char **env);
t_param	*get_param(t_param *params, char *key);
void	add_var(t_param **param, char *key, char *value);
void	free_params(t_param *params);
char	**append_to_array(char	**array, char *new_string);

#endif
