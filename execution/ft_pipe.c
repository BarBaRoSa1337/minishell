/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:46:44 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/04 17:46:45 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	child_process_1(char **av, char **env, int *fd, t_var *var)
{
	int	pid;
	int	in;

	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		in = open(av[1], O_RDONLY);
		if (in == -1)
		{
			perror(av[1]);
			exit(0);
		}
		dup2(in, 0);
		close(in);
		dup2(fd[1], 1);
		close(fd[1]);
		if (execve(var->cmd_path_1, var->cmd_1, env) == -1)
			exit(0);
	}
	return (pid);
}

int	child_process_2(char **av, char **env, int *fd, t_var *var)
{
	int	pid;
	int	out;

	pid = fork();
	if (pid == 0)
	{
		close(fd[1]);
		out = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (out == -1)
		{
			perror(av[4]);
			exit(0);
		}
		dup2(out, 1);
		close(out);
		dup2(fd[0], 0);
		close(fd[0]);
		if (execve(var->cmd_path_2, var->cmd_2, env) == -1)
			exit(0);
	}
	return (pid);
}

void	ft_pipe(char **av, char **env, t_var *var)
{
	int	fd[2];
	int	pid;
	int	pid2;

	pipe(fd);
	pid = child_process_1(av, env, fd, var);
	pid2 = child_process_2(av, env, fd, var);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid, NULL, 0);
	waitpid(pid2, NULL, 0);
	return ;
}
