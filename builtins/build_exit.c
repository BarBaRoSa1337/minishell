#include "../minishell.h"

int its_num(char *str)
{
        int i;
        
        i = 0;
        while (str[i])
        {
                if (str[i] >= 48 && str[i] <= 57)
                        i++;
                else
                        return (-1);
        }
        return (0);
}

void build_exit(char *status)
{
        if (!status)
                exit(0);
        else if (its_num(status) == -1)
        {
                ft_printf("exit: %s: numeric argument required", status);
                exit(2);
        }
        else if (its_num(status) == 0) 
                exit(ft_atoi(status));
}

