#include "../minishell.h"

void build_echo(char *str, int nl, int fd)
{
    if (str)
    {
        ft_putstr_fd(str, fd);
        if (nl == 1)
            ft_putchar_fd('\n', fd);
    }
    return ;
}
