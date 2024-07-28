#include "../execution.h"

int    execute_builtins(t_ms *e, t_env **v)
{
    if (ft_strncmp(e->cmd, "cd", sizeof(e->cmd)) == 0)
        build_cd(e->arg);
    else if (ft_strncmp(e->cmd, "echo", sizeof(e->cmd)) == 0)
        build_echo(e->arg, 1);
    else if (ft_strncmp(e->cmd, "unset", sizeof(e->cmd)) == 0)
        build_unset(e->arg, v);
    else if (ft_strncmp(e->cmd, "pwd", sizeof(e->cmd)) == 0)
        build_pwd();
    else if (ft_strncmp(e->cmd, "export", sizeof(e->cmd)) == 0)
        build_export(e->arg, v);
    else if (ft_strncmp(e->cmd, "env", sizeof(e->cmd)) == 0)
        build_env((*v));
    else if (ft_strncmp(e->cmd, "exit", sizeof(e->cmd)) == 0)
        build_exit(e->arg);
    else
        return (-1);
    return (0);
}
