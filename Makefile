SRC = main.c run_command.c\
	lex/lexer.c\
	parsing/parser.c parsing/expand_params.c\
	execution/executor.c\
	utils/env_utils.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
READLINE = -lreadline -I/usr/local/opt/readline/include -L/usr/local/opt/readline/lib
NAME = minishell
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(SRC) $(LIBFT)
	$(CC) $(CFLAGS) $(READLINE) $(LIBFT)  $^ -o $@

$(LIBFT):
	make all -C libft

clean:
	make clean -C libft

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all
