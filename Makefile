SRC = main.c run_command.c\
	parsing/parser.c parsing/expand_params.c parsing/parse_files.c parsing/join_quoted.c\
	lex/lexer.c lex/quote_validity.c lex/redirect_validity.c  lex/split_by_qoute.c lex/split_by_redirect.c lex/split_by_space.c\
	execution/executor.c execution/duplicate_fds.c\
	utils/append_array.c utils/env_utils.c utils/quote_utils.c utils/costum_trim.c utils/file_utils.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror --fsanitise=address
READLINE = -lreadline
NAME = minishell
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(SRC) $(LIBFT)
	$(CC) $(READLINE) $(LIBFT)  $^ -o $@

$(LIBFT):
	make all -C libft

clean:
	make clean -C libft

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all
