#include "minishell.h"

char **get_envp(char **env)
{
    char **envp;
    char *str;
    int i;
    
    i = 0;
    while(env[i])
    {
        str = ft_strjoin(str, env[i]);
        str = ft_strjoin(str, ft_strdup("\n"));
        i++;
    }
    envp = ft_split(str, '\n');
    return (envp);
}