#include "../execution.h"

void    build_env(t_env *v)
{
    while(v)
    {
        if (v->value != NULL && v->value[0] != '\0')
        {
            ft_putstr_fd(v->key, 1);
            ft_putchar_fd('=', 1);
            ft_putstr_fd(v->value, 1);
            ft_putchar_fd('\n', 1);
        }
        v = v->next;
    }
    return ;
}

