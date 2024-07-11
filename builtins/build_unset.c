#include "../minishell.h"

void    build_unset(char **str, t_env **v)
{
    t_env *head;
    t_env *tmp;
    int i;

    head = (*v);
    while(head)
    {
        i = 0;
        while(str[i])
        {
            if (ft_strncmp(str[i], head->key, sizeof(str[i])) == 0)
            {
                //delete node
                tmp->next = head->next;
                free(head);
                break;
            }
            i++;
        }
        tmp = head;
        head = head->next;
    }
    return ;
}

