#include "../minishell.h"

void execute_cmd(t_minishell *e)
{
    if (e->next != NULL)
        ft_pipe();
    else
        simple_execute();
}