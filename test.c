#include "minishell.h"

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;
	execve("./minishell", (char*[2]){"minishell", NULL}, NULL);
}

