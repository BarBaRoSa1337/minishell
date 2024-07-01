#include "minishell.h"

int main(int ac, char **av, char **env)
{
    t_shell *shell;
    t_minishell *my_struct;
    
    my_struct = ft_lstnew();
    shell = parsing(ac, av, env);
    ft_linked_list(&my_struct, shell);
    execute(my_struct);
}