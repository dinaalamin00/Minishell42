/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:59:15 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/08 17:34:12 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define RD 0
# define WR 1
# define APPEND 2
# define RDWR 3
# define HERE_DOC 4

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <fcntl.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"
# include "GNL/get_next_line.h"

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
void	redirect_validity(t_mshell *shell);
int		is_redirect(char c);
void	split_by_quote(t_mshell *shell);
void	split_by_redirect(t_mshell *shell);
void	split_by_space(t_mshell *shell);

//parser
void	parser(t_mshell *shell, char **env);
void	expand_params(t_mshell *shell);
void	expand_string(t_mshell *shell, char **str);
void	parse_files(t_mshell *shell);
void	join_quote(t_mshell *shell);
void	clean_command(t_mshell *shell);

//executor
void	executor(t_mshell *shell, char **env);
void	open_dup(t_mshell *shell);
void	execute_command(t_mshell *shell, char **env);
void	ft_echo(t_mshell *shell);
void	ft_export(t_mshell *shell);
void	ft_env(t_mshell *shell, int export);
void	ft_pwd(t_mshell *shell);
void	ft_unset(t_mshell *shell);
void	ft_cd(t_mshell *shell);
void	execute_external(t_mshell *shell, char **env);

//utils
void	env_to_list(t_mshell *shell, char **env);
void	add_var(t_param **param, char *str);
t_param	*get_param(t_param *params, char *key);
int		valid_key(char *key);
void	del_var(t_param **param, char *key);
void	free_params(t_param *params);
char	**append_to_array(char	**array, char *new_string);
int		array_len(char	**array);
char	*custom_trim(char *s1, char c, int pos);
void	close_quote(char **str, char *next_str);
void	flst_addback(t_flist **lst, char *name, int mode);
void	flst_clear(t_flist **lst);
int		array_len(char	**array);
void	display_vars(t_param *param, int export);

//error
void    key_error(char *cmd, char *key);
#endif
