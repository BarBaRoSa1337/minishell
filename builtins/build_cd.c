#include "../minishell.h"

void build_cd(char *direction)
{
        if (direction)
        {
                if (chdir(direction) == -1)
                        perror(direction);
        }
	return ;
}

