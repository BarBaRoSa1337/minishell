/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_to_shadi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 10:44:45 by achakour          #+#    #+#             */
/*   Updated: 2024/09/12 23:39:25 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	open_files2(t_a9aw9o3 *iter, t_shell *tokens, t_heredoc **heredoc)
{
	if (iter->type == 5 && !ft_strchar(iter->cmd, ">>") && ft_strcmp(iter->cmd,
			"/dev/stdout") != 0)
	{
		if (tokens->out != -1)
		{
			if (tokens->out != 1)
				close(tokens->out);
			tokens->out = open(iter->cmd, O_RDWR | O_CREAT | O_APPEND, 0664);
			if (tokens->out == -1 && tokens->err != 1)
			{
				perror(iter->cmd);
				g_exit_status = 1;
			}
		}
	}
	else if (iter->type == 6 && !ft_strchar(iter->cmd, "<<"))
	{
		if (tokens->in != -1)
		{
			if (tokens->in != 0)
				close(tokens->in);
			tokens->in = (*heredoc)->fd;
		}
		(*heredoc) = (*heredoc)->next;
	}
}

void	open_files(t_a9aw9o3 *iter, t_shell *tokens, t_heredoc **her)
{
	if (iter->type == 4 && !ft_strchar(iter->cmd, "<"))
	{
		if (tokens->in != -1)
			open_infile(iter, tokens);
	}
	else if (iter->type == 3 && !ft_strchar(iter->cmd, ">")
		&& ft_strcmp(iter->cmd, "/dev/stdout") != 0)
	{
		if (tokens->out != -1)
		{
			if (tokens->out != 1)
				close(tokens->out);
			tokens->out = open(iter->cmd, O_RDWR | O_CREAT | O_TRUNC, 0664);
			if (tokens->out == -1 && tokens->err != 1)
			{
				perror(iter->cmd);
				g_exit_status = 1;
			}
		}
	}
	else
		open_files2(iter, tokens, her);
}

t_pars	*init_p(t_a9aw9o3 **cmd, t_env *env)
{
	t_pars	*p;

	p = malloc(sizeof(t_pars));
	if (!p)
		return (NULL);
	p->tokens = tokens_new();
	p->iter = *cmd;
	p->arg_strct = NULL;
	p->heredoc = heredoc_iter(p->iter, env);
	p->her_head = p->heredoc;
	return (p);
}

void	fill_cmd(t_pars *p)
{
	if (p->iter->err == 1)
		p->tokens->err = 1;
	if (p->iter->type == 1)
		p->tokens->cmd = ft_strdup(p->iter->cmd);
}

t_shell	*fill_struct(t_a9aw9o3 **cmd, t_env *env)
{
	t_shell	*head;
	t_pars	*p;

	if (!cmd || !(*cmd))
		return (NULL);
	p = init_p(cmd, env);
	head = p->tokens;
	while (p->iter && p->tokens)
	{
		fill_cmd(p);
		if (p->iter->type == 2)
			lst_rje3_lor(&(p->arg_strct), arg_new(p->iter->cmd));
		else
			open_files(p->iter, p->tokens, &p->heredoc);
		if (p->iter->type == 7 || p->iter->next == NULL)
		{
			(p->tokens)->args = p->arg_strct;
			p->arg_strct = NULL;
			if (p->iter->type == 7)
				p->tokens->next = tokens_new();
			p->tokens = p->tokens->next;
		}
		p->iter = p->iter->next;
	}
	return (ft_cmd_clear(cmd, p), head);
}
