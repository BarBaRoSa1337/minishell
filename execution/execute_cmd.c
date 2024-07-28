#include "../execution.h"

void execute_cmd(t_ms **e, t_env *v, char **envp, int tmp)
{
    int fd[2];
    int pid;

    if (!(*e))
        return;
    check_cmd(e, v);
    while((*e))
    {
        if ((*e)->next)
        {
            pipe(fd);
            if ((*e)->infile == 0 && (*e)->pid)
            {
                if(tmp)
                    (*e)->infile = tmp;
                else
                    (*e)->infile = fd[0];
            }
            if ((*e)->outfile == 1 && (*e)->next)
                (*e)->outfile = fd[1];
        }
        
        pid = simple_execute((*e), envp);
        close(fd[0]);
        close(fd[1]);
        waitpid(pid, NULL, 0);
        // tmp = fd[1];
        dup2(tmp, fd[1]);
        (*e) = (*e)->next;
    }
}
