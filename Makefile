SRC = main.c run_command.c gnl/get_next_line.c gnl/get_next_line_utils.c signals.c shell_initialization.c\
	parsing/parser.c parsing/expand_params.c parsing/parse_files.c parsing/join_quoted.c parsing/clean_command.c parsing/here_doc.c\
	tokenization/pipe_check.c tokenization/pipe_validity.c tokenization/quote_validity.c tokenization/redirect_validity.c\
	tokenization/split_by_pipe.c tokenization/split_by_qoute.c tokenization/split_by_redirect.c tokenization/split_by_space.c tokenization/tokenizer.c\
	execution/executor.c execution/duplicate_fds.c execution/execute_command.c execution/execute_external.c execution/pipe.c execution/check_accessibility.c\
	execution/ft_echo.c execution/ft_export.c execution/ft_env.c execution/ft_pwd.c execution/ft_unset.c execution/ft_cd.c execution/ft_exit.c\
	utils/append_array.c utils/env_utils.c utils/quote_utils.c utils/custom_trim.c utils/file_utils.c utils/errors.c utils/memory_utils.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
READLINE = -I/Users/$(USER)/homebrew/opt/readline/include -L/Users/$(USER)/homebrew/opt/readline/lib -lreadline
NAME = minishell
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(SRC) $(LIBFT)
	$(CC) $(CFLAGS) $(READLINE) $(LIBFT) $^ -o $@ -l readline

$(LIBFT):
	make all -C libft

clean:
	make clean -C libft

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all
