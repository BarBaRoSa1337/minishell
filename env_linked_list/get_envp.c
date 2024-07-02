#include "../minishell.h"

void get_envp(char **envp, t_env **head)
{
	t_env	*new;
	int		l;

	l = 0;
	while (envp[l])
	{
        new = split_env(envp[l]);
		env_lstadd_back(head, new);
		l++;
	}
	return ;
}
