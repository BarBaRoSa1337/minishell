#include "../minishell.h"

void build_pwd(void)
{
        char path[PATH_SIZE];

        if (getcwd(path, sizeof(path)) == NULL)
                perror("Error\n");
        
        printf("path = %s\n", path);
        ft_putstr_fd(path, 1);
        ft_putchar_fd('\n', 1);
	return ;
}
