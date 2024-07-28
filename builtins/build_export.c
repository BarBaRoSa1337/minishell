#include "../execution.h"

void    build_export(char **str, t_env **v)
{
    t_env *new;
    t_env *head;
    int i;

    i = 0;
    if (str && str[i])
    {
        while(str[i])
        {
            new = split_env(str[i]);
            env_lstadd_back(v, new);
            i++;
        }
    }
    else
    {
        head = (*v);
        while(head)
        {
            ft_putstr_fd(head->key, 1);
            ft_putchar_fd('=', 1);
            if (head->value)
                ft_putstr_fd(head->value, 1);
            ft_putchar_fd('\n', 1);
            head = head->next;
        }
    }
    return ;
}

