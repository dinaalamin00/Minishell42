SRC = main.c run_command.c lex/lexer.c parsing/parser.c execution/executor.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
READLINE = -lreadline -I/usr/local/opt/readline/include -L/usr/local/opt/readline/lib
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
