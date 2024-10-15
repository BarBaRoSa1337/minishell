/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_execute.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:47:17 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/12 22:53:31 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	close_fd(int in, int out)
{
	if (in != 0)
		close(in);
	if (out != 1)
		close(out);
}

void	dup_fd(int in, int out, int pipe_in)
{
	if (pipe_in != -1)
		close(pipe_in);
	if (in != 0)
	{
		dup2(in, 0);
		close(in);
	}
	if (out != 1)
	{
		dup2(out, 1);
		close(out);
	}
}

int	simple_execute(t_ms *e, char **env, t_env **v, int pipe_in)
{
	int	pid;

	if (is_builtins(e) == 1 && !e->next && e->infile != -1 && e->outfile != -1
		&& e->error == 0 && e->outfile == 1 && e->pid == 0)
	{
		dup_fd(e->infile, e->outfile, -1);
		execute_builtins(e, v);
		return (0);
	}
	pid = fork();
	if (pid == 0)
	{
		if (e->infile != -1 && e->outfile != -1 && e->error == 0)
		{
			dup_fd(e->infile, e->outfile, pipe_in);
			if (execute_builtins(e, v) == -1)
				if (execve(e->cmd, e->arg, env) == -1)
					exit(127);
		}
		exit(0);
	}
	else if (pid > 0)
		close_fd(e->infile, e->outfile);
	return (pid);
}
