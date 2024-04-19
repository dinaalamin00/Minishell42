/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:59:15 by diahmed           #+#    #+#             */
/*   Updated: 2024/04/19 19:16:09 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define RD 0
# define WR 1
# define APPEND 2
# define RDWR 3
# define HERE_DOC 4

# define SUCCESS 1
# define FAILURE 0

# include <stdio.h>
# include <stdbool.h>
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
	int		exit_code;
	int		orig_stdin;
	int		orig_stdout;
}	t_mshell;

void	run_command(t_mshell *shell, char **env);

//lexer
int		lexer(t_mshell *shell);
bool	quote_validity(t_mshell *shell);
bool	is_quote(char c);
bool	redirect_validity(t_mshell *shell);
bool	is_redirect(char c);
bool	split_by_quote(t_mshell *shell);
bool	split_by_redirect(t_mshell *shell);
bool	split_by_space(t_mshell *shell);

//parser
int		parser(t_mshell *shell, char **env);
bool	expand_params(t_mshell *shell);
bool	expand_string(t_mshell *shell, char **str);
bool	parse_files(t_mshell *shell);
bool	join_quote(t_mshell *shell);
bool	clean_command(t_mshell *shell);

//executor
int		executor(t_mshell *shell, char **env);
void	open_dup(t_mshell *shell);
void	reset_fds(t_mshell *shell);
void	execute_command(t_mshell *shell, char **env);
void	ft_exit(t_mshell *shell);
void	ft_echo(t_mshell *shell);
void	ft_export(t_mshell *shell);
void	ft_env(t_mshell *shell, int export);
void	ft_pwd(t_mshell *shell);
void	ft_unset(t_mshell *shell);
void	ft_cd(t_mshell *shell);
void	execute_external(t_mshell *shell, char **env);

//utils
bool	env_to_list(t_mshell *shell, char **env);
bool	add_var(t_mshell *shell, char *str);
int		valid_key(char *key);
int		valid_value(char *value);
t_param	*get_param(t_param *params, char *key);
int		valid_key(char *key);
void	del_var(t_param **param, char *key);
void	free_params(t_param *params);
char	**append_to_array(t_mshell *shell, char	**array, char *new_string);
int		array_len(char	**array);
char	*custom_trim(char *s1, char c, int pos);
bool	close_quote(char **str, char *next_str);
bool	flst_addback(t_flist **lst, char *name, int mode);
void	flst_clear(t_flist **lst);
int		array_len(char	**array);
void	free_shell(t_mshell *shell, int param_flag, int exit_flag);
int		is_alldigit(char *str);
// void	display_vars(t_param *param, int export);

//error
void	key_error(char *cmd, char *key);
void	command_error(t_mshell *shell, t_param	*path, char *message);
void	malloc_error(t_mshell *shell,  int param_flag, int exit_flag);
#endif
