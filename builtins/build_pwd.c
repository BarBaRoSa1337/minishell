#include "../minishell.h"

void build_pwd(void)
{
        char path[MAX_PATH];
        if (getcwd(path, sizeof(path)) == NULL)
                perror("Error\n");
        ft_putstr_fd(path, 1);
        ft_putchar_fd('\n', 1);
	return ;
}
