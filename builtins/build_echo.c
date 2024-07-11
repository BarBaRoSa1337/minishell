#include "../minishell.h"

int its_n(char *str)
{
    int i;
    
    i = 0;
    if (str[i] == '-')
        i++;
    else
        return (-1);
    while(str[i])
    {
        if (str[i] == 'n')
            i++;
        else
            return (-1);
    }
    return (1);
}

void build_echo(char **arg, int fd)
{
    int i;
    int nl;

    i = 0;
    nl = 1;
    if (!arg || !arg[0])
    {
        ft_putstr("\n", fd);
        return ;
    }
    while (arg[i])
    {
        if (arg[0][0] == '-')
        {
            if (its_n(arg[0]) == 1)
                nl = 0;
            else 
                nl = 1;
            i++;
        }
        else if (arg[i][0] == '-')
        {
            if (its_n(arg[0]) == 1)
                i++;
            else 
                break ;
        }
        else
            break ;
    }
    while (arg[i])
    {
        ft_putstr_fd(arg[i], fd);
        ft_putchar_fd(' ', fd);
        i++;
    }
    if (nl == 1)
        ft_putchar_fd('\n', fd);
    return ;
}
