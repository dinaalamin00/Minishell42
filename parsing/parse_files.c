
#include "../minishell.h"

// char	**pre_quote(char **new_token, char	**token)
// {
	
// }

char	**join_to_last(char	**array, char *new_string)
{
	char	*temp;
	char	*new_temp;
	char	symbol;
	char	*spaces;
	int		i;

	i = 0;
	while (array[i])
		i++;
	i--;
	symbol = array[i][ft_strlen(array[i]) - 1];
	temp = ft_strdup(array[i]);
	new_temp  =ft_strdup(new_string);
	if (ft_strset(new_string, "\'\""))
		new_temp = costum_trim(new_temp, *new_temp, 1);
	temp = ft_strjoin(costum_trim(temp, symbol, 2), new_temp);
	if (ft_strset(new_string, "\'\""))
	{
		spaces = ft_strrset(temp, "\'\"");
		temp = costum_trim(temp, 32, 2);
		temp = costum_trim(temp, *spaces, 2);
	}
	close_quote(&temp, symbol);
	temp = ft_strjoin(temp, spaces + 1);
	// free(array[i]);
	array[i] = temp;
	// free(new_temp);
	return (array);
}

char	**post_quote(char **new_token, t_mshell *shell)
{
	int		i;
	char	*temp;
	char	symbol;

	i = 0;
	// printf("test");
	while (shell->tokens[i])
	{
		append_to_array(new_token, shell->tokens[i]);
		while (ft_strset(shell->tokens[i], "\'\""))
		{
			if (is_quote(shell->tokens[i][ft_strlen(shell->tokens[i]) - 1]) && shell->tokens[i + 1])
			{
				i++;
				new_token = join_to_last(new_token, shell->tokens[i]);
			}
			else
				break ;
		}	
		i++;
	}
	// free(token);
	return (new_token);
}

void	join_quote(t_mshell *shell)
{
	char	**new_token;

	new_token = malloc(1*sizeof(char *));
	if (!new_token)
		return ;
	new_token[0] = NULL;
	printf("test");
	shell->tokens = post_quote(new_token, shell);

}

void	parse_files(t_mshell *shell)
{
	join_quote(shell);
}