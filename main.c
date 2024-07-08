#include "minishell.h"

void    builtins(char *str, t_env **v)
{
    if (ft_strncmp(str, "cd\n", sizeof(str)) == 0)
        build_cd("..");
    else if (ft_strncmp(str, "echo\n", sizeof(str)) == 0)
        build_echo("salam", 1, 1);
    else if (ft_strncmp(str, "unset\n", sizeof(str)) == 0)
        build_unset("PATH", v);
    else if (ft_strncmp(str, "pwd\n", sizeof(str)) == 0)
        build_pwd();
    else if (ft_strncmp(str, "export\n", sizeof(str)) == 0)
        build_export("wa fine", v);
    else if (ft_strncmp(str, "env\n", sizeof(str)) == 0)
        build_env((*v));
    else if (ft_strncmp(str, "exit\n", sizeof(str)) == 0)
        build_exit(1);
    else
        printf("dinied\n");
}

int main(int ac, char **av, char **env)
{
    t_env *v = NULL;
    t_shell *p = NULL;
    t_minishell *e = NULL; 
    
    get_envp(env, &v);
    parssing(ac, av, env, &p);
    forming_list(&e, p);
    execute_cmd(e);
} 