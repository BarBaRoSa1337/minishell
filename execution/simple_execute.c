#include "../minishell.h"

int	simple_execute(t_ms *e, char **env)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(e->infile, 0);
		close(e->infile);
		dup2(e->outfile, 1);
		close(e->outfile);
		
		printf("[%s]  args: %s\n", e->cmd, e->arg[0]);

		if (execve(e->cmd, e->arg, env) == -1)
		{
			printf("error\n");
			exit(0);
		}
	}
	return (pid);
}