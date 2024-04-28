#include "../minishell.h"

static int	valid_pipe(char *user_input)
{
	int		i;
	char	*str;

	i = 0;
	str = user_input;
	while (str_pipe(str))
	{
		i = 0;
		str = str_pipe(str) + 1;
		while (str[i] == 32 && str[i])
			i++;
		if (!str[i] || str[i] == '|')
			return (0);
	}
	return (1);
}

bool	pipe_validity(t_mshell *shell)
{
	if (!valid_pipe(shell->user_input))
	{
		ft_putendl_fd("syntax error, unexpected token", 2);
		free_shell(shell, 0, -1);
		return (FAILURE);
	}
	return (SUCCESS);
}
