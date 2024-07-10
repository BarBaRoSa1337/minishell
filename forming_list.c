#include "minishell.h"

void forming_list(t_ms **my_struct, t_shell *shell)
{
    t_ms *head;
    t_ms *new;
    int id = 0;

    head = *my_struct;
    while(shell)
    {
        head->pid = id;
        id++;
        if (shell->type == 1)
            head->infile = shell->arg;
        else if (shell->type == 2)
            head->cmd = shell->arg;
        else if (shell->type == 3)
            head->arg = shell->arg;
        else if (shell->type == 4)
            head->outfile = shell->arg;
        else if (shell->type == 5)
        {
            new = ft_lstnew();
            ft_lstadd_back(my_struct, new);
            head = head->next;
        }
        shell = shell->next;
    }
}
