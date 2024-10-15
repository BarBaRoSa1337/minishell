/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:45:56 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/12 22:54:53 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	fr_ms(t_ms *ms)
{
	if (!ms)
		return ;
	free(ms->cmd);
	ft_free(ms->arg);
	free(ms);
}

void	set_fds(t_ms *head, int tmp, int *fd)
{
	if (head->infile == 0 && head->pid != 0)
		head->infile = tmp;
	if (head->outfile != -1 && head->next)
		head->outfile = fd[1];
}

void	execute_cmd(t_ms **e, t_env **v, char **envp, int tmp)
{
	int		fd[2];
	t_ms	*head;

	check_cmd(e, (*v));
	head = *e;
	while (head)
	{
		if (head->next)
		{
			pipe(fd);
			set_fds(head, tmp, fd);
			simple_execute(head, envp, v, fd[0]);
			close(fd[1]);
			tmp = fd[0];
		}
		else
		{
			if (head->infile == 0 && head->pid != 0)
				head->infile = tmp;
			simple_execute(head, envp, v, -1);
		}
		head = head->next;
	}
	while (wait(NULL) != -1)
		;
}
