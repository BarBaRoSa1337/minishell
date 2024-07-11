#include "../minishell.h"

int	simple_execute(t_ms *e, char **env)
{
	int	pid;
	int	in;
    int out;

	pid = fork();
	if (pid == 0)
	{
		dup2(in, 0);
		close(in);
		dup2(out, 1);
		close(out);
		if (execve(e->cmd, e->arg, env) == -1)
			exit(0);
	}
	return (pid);
}