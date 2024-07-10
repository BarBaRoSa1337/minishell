#include "../minishell.h"


void execute_cmd(t_ms *e, t_env *v, char **envp, int tmp)
{
    char *env;
    int fd[2];
    int tmp;

    if (!e)
        return;
    env = searsh_env(v);
    // check_cmd(e->cmd, env);
    if (e != NULL)
    {
        pipe(fd);
        if (e->infile == 0 && e->pid)
        {
            if(tmp)
                e->infile = tmp;
            else
                e->infile = fd[0];
        }
        if (e->outfile == 1 && e->next)
            e->outfile = fd[1];
    }
    simple_execute(e, envp);
    tmp = fd[1];
    // dup2(tmp, fd[1]);

    execute_cmd(e->next, tmp);
}