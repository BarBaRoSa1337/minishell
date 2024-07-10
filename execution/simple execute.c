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
		if (execve(var->cmd_path_1, var->cmd_1, env) == -1)
			exit(0);
	}
	return (pid);
}