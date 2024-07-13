#include "minishell.h"


int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;

    t_ms *e;
    t_env *v;
    v = NULL;
    get_envp(env, &v);

    // t_shell *p;
    // char *input;
    // readline(input);
    // p = NULL;
    // parssing(input, &p);
    // forming_list(&e, p);

    e = ft_lstnew();
    node_1(&e);
    e->next = ft_lstnew();
    node_2(&e->next);
    e->next->next = ft_lstnew();
    node_3(&e->next->next);
    
    if (execute_builtins(e, &v) == -1)
    {
        execute_cmd(&e, v, env, 0);
    }
}
