#include "minishell.h"


int main(int ac, char **av, char **env)
{
    t_ms *e = NULL; 
    t_env *v = NULL;
    t_shell *p = NULL;
    
    get_envp(env, &v);
    // parssing(ac, av, env, &p);
    e = ft_lstnew();
    forming_list(&e, p);
    if (execute_builtins(e, &v) == -1)
        execute_cmd(e, v, env, 0);
}
