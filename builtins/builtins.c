#include "../minishell.h"

void build_cd(const char *direction)
{
	if (direction)
	{
		if (chdir(direction) == -1)
			perror(direction);
	}
}

void build_exit(int status)
{
	exit(status);
}

void build_pwd(void)
{
	char path[PATH_MAX];
	if (getcwd(path, sizeof(path)) == NULL)
		perror("Error\n");
	printf("%s\n", path);
}

void build_echo(char *str, char *file_name)
{
    int fd;

    if (str)
    {
        if (file_name)
        {
            fd = open(file_name, O_RDWR, 644);
            ft_putstr_fd(str, fd);
        }
        ft_putstr_fd(str, 1);
    }
}

void    build_env(t_env *v)
{
    while(v)
    {
        if (v->value)
        {
            ft_putstr_fd(v->key, 1);
            ft_putchar_fd('=', 1);
            ft_putstr_fd(v->value, 1);
            ft_putchar_fd('\n', 1);
        }
        v = v->next;
    }
}

void    build_export(char *str, t_env **v)
{
    t_env *new;

    if (str)
    {
        new = env_lstnew();
        split_env(str, &new);
        env_lstadd_back(v, new);
    }
    else
    {
        while((*v))
        {
            ft_putstr_fd((*v)->key, 1);
            ft_putchar_fd('=', 1);
            if ((*v)->value)
                ft_putstr_fd((*v)->value, 1);
            ft_putchar_fd('\n', 1);
            (*v) = (*v)->next;
        }
    }
    return ;
}

void    build_unset(char *str, t_env **v)
{
    t_env *head;

    head = (*v);
    while(head)
    {
        if (ft_strncmp(head->key, str) == 0)
        {
            //delete node
            break;
        }
        head = head->next;
    }
}