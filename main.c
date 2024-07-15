#include "minishell.h"


int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;

    t_ms *e;
    t_env *v;
    t_shell *p;
    v = NULL;
    get_envp(env, &v);

    // char *input;
    // readline(input);
    // parssing(input, &p);

    p = new_node();
    node_1(p);
    p->next = new_node();
    node_2(p->next);
    p->next->next = new_node();
    node_3(p->next->next);
    
    e = ft_lstnew();
    forming_list(&e, p);
    
    if (execute_builtins(e, &v) == -1)
    {
        execute_cmd(&e, v, env, 0);
    }
}
