#include "minishell.h"

// char **get_envp(char **env)
// {
//     char **envp;
//     char *str;
//     int i;
    
//     i = 0;
//     while(env[i])
//     {
//         str = ft_strjoin(str, env[i]);
//         str = ft_strjoin(str, ft_strdup("\n"));
//         i++;
//     }
//     envp = ft_split(str, '\n');
//     return (envp);
// }

void split_env(char *str, t_env **v)
{
    int i;

    j = 0;
    i = 0;
    while(str[i] != '=' && str[i])
        (*v)->key[i++] = str[i++];
    (*v)->key = '\0';
    if (str[i] == '=')
    {
        i++;
        while(str[i])
            (*v)->value[j++] = str[i++];
        (*v)->value[j] = '\0';
    }
    else
        (*v)->value = NULL;
}

void getenvp(char **envp, t_env **head)
{
    // char **envp = get_envp(env);
    t_env	*new;
	int		l;

	l = 0;
	while (envp[l])
	{
		new = ft_lstnew();
        split_env(envp[l], &new);
		ft_lstadd_back(head, new);
		l++;
	}
	return ;
}