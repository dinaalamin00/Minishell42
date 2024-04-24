SRC = main.c run_command.c gnl/get_next_line.c gnl/get_next_line_utils.c signals.c\
	parsing/parser.c parsing/expand_params.c parsing/parse_files.c parsing/join_quoted.c parsing/clean_command.c\
	lex/lexer.c lex/quote_validity.c lex/redirect_validity.c  lex/split_by_qoute.c lex/split_by_redirect.c lex/split_by_space.c\
	execution/executor.c execution/duplicate_fds.c execution/execute_command.c execution/execute_external.c\
	execution/ft_echo.c execution/ft_export.c execution/ft_env.c execution/ft_pwd.c execution/ft_unset.c execution/ft_cd.c execution/ft_exit.c\
	utils/append_array.c utils/env_utils.c utils/quote_utils.c utils/custom_trim.c utils/file_utils.c utils/errors.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
READLINE = -I/Users/$(USER)/homebrew/opt/readline/include -L/Users/$(USER)/homebrew/opt/readline/lib -lreadline
NAME = minishell
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(SRC) $(LIBFT)
	$(CC) $(READLINE) $(LIBFT)  $^ -o $@ -l readline

$(LIBFT):
	make all -C libft

clean:
	make clean -C libft

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all
