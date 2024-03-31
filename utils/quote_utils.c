
#include "../minishell.h"

void	close_quote(char **str, char symbol)
{
	char	*temp;
	int		i;

	temp = malloc (ft_strlen(*str) + 2);
	if (!temp)
		return ;
	while (*str[i])
	{
		temp[i] = *str[i];
		i++;
	}
	temp[i++] = symbol;
	temp[i] = '\0';
	free(*str);
	*str = temp;
}
