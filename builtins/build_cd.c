#include "../execution.h"

void build_cd(char **direction)
{
        if (direction)
        {
                if (multiple_arg(direction) == 1)
                {
                        ft_printf("cd: too many arguments\n");
                        exit(1);
                }
                if (chdir(direction[0]) == -1)
                        perror(direction[0]);
        }
	return ;
}

