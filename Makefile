SRC = main.c run_command.c lex/lexer.c lex/quotes.c lex/redirect_validity.c  lex/split_by_qoute.c lex/split_by_redirect.c parsing/parser.c execution/executor.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
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
