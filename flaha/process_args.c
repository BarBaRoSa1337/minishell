/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:38:41 by achakour          #+#    #+#             */
/*   Updated: 2024/09/12 23:38:45 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	sanitize_tokens(t_a9aw9o3 *cmd)
{
	t_pars	p;

	p.before = 0;
	p.head = cmd;
	p.cmd_found = 0;
	while (p.head)
	{
		if (p.head->type > 2 && p.head->type < 7)
			p.before = p.head->type;
		else if (p.before != 0)
		{
			p.head->type = p.before;
			p.before = 0;
		}
		else if (p.cmd_found == 0 && p.head->type != 7)
		{
			p.cmd_found = 1;
			p.head->type = 1;
		}
		else if (p.cmd_found == 1 && p.head->type == 0)
			p.head->type = 2;
		else if (p.head->type == 7)
			p.cmd_found = 0;
		p.head = p.head->next;
	}
}

void	process_red(t_a9aw9o3 *cmd)
{
	t_a9aw9o3	*head;
	char		*str;

	if (!cmd)
		return ;
	head = cmd;
	while (head)
	{
		str = head->cmd;
		if (head->quoted == 0 && str[0] == '>' && str[1] == '>')
			head->type = 5;
		else if (head->quoted == 0 && ft_strchar(head->cmd, ">"))
			head->type = 3;
		else if (head->quoted == 0 && str[0] == '<' && str[1] == '<')
			head->type = 6;
		else if (head->quoted == 0 && ft_strchar(head->cmd, "<"))
			head->type = 4;
		else if (head->quoted == 0 && ft_strchar(head->cmd, "|"))
			head->type = 7;
		else
			head->type = 0;
		head = head->next;
	}
}

char	*ft_replace(char *cmd, int len, int flag)
{
	t_pars	p;

	p.i = 0;
	p.j = 0;
	if (len == 0)
		return (free(cmd), ft_strdup("\0"));
	p.buff = malloc(len + 1);
	while (cmd[p.i])
	{
		if (cmd[p.i] == '\'' && flag == 0)
			flag = 1;
		else if (cmd[p.i] == '\"' && flag == 0)
			flag = 2;
		else if (((cmd[p.i] == '\'' && flag == 1) || (cmd[p.i] == '\"'
					&& flag == 2) || (cmd[p.i] == '\"' && flag == 2)))
			flag = 0;
		else if (!(cmd[p.i] == '$' && (cmd[p.i + 1] == '\"' || cmd[p.i
						+ 1] == '\'') && get_qoutes(cmd, p.i) == 0))
			p.buff[p.j++] = cmd[p.i];
		++p.i;
	}
	p.buff[p.j] = '\0';
	return (free(cmd), p.buff);
}

void	remove_quotes(t_a9aw9o3 *bash)
{
	t_pars	p;

	p.flag = 0;
	while (bash && bash->cmd && bash->err != 2)
	{
		p.i = 0;
		p.j = 0;
		while (bash->cmd[p.j])
		{
			if (bash->cmd[p.j] == '\'' && p.flag == 0)
				p.flag = 1;
			else if (bash->cmd[p.j] == '\"' && p.flag == 0)
				p.flag = 2;
			else if ((bash->cmd[p.j] == '\'' && p.flag == 1)
				|| (bash->cmd[p.j] == '\"' && p.flag == 2))
				p.flag = 0;
			else
				++p.i;
			++p.j;
		}
		if (ft_strchar(bash->cmd, "\'\""))
			bash->cmd = ft_replace(bash->cmd, p.i, p.flag);
		bash = bash->next;
	}
}
