#include "../minishell.h"

void    build_export(char *str, t_env **v)
{
    t_env *new;
    t_env *head;

    if (str)
    {
        new = split_env(str);
        env_lstadd_back(v, new);
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

