#include "minishell.h"

int main(int ac, char **av, char **env)
{
    t_env *v;
    t_shell *s_parsing;
    t_minishell *s_execution;
    
    getenvp(env, &v);
    s_parsing = parsing(ac, av, env);
    s_execution = ft_lstnew();
    forming_list(&s_execution, s_parsing);
    execute(s_execution);
}