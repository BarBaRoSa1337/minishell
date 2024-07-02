#include "../minishell.h"

void    build_unset(char *str, t_env **v)
{
    t_env *head;
        t_env *tmp;

    head = (*v);
    while(head)
    {
        if (ft_strncmp(head->key, str, sizeof(head->key)) == 0)
        {
            //delete node
            tmp->next = head->next;
            free(head);
            break;
        }
        tmp = head;
        head = head->next;
    }
    return ;
}

