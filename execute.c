#include "minishell.h"

void    execute(char *cmd, char **env)
{
    char **envp;

    envp = get_envp(env);
    
    int i = 0;
    while(envp[i])
    {
        printf("%s\n", envp[i]);
        i++;
    }
    return ;
}