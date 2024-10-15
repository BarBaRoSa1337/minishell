/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 22:01:23 by achakour          #+#    #+#             */
/*   Updated: 2024/09/12 23:37:17 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	open_infile(t_a9aw9o3 *iter, t_shell *tokens)
{
	if (tokens->in != 0)
		close(tokens->in);
	tokens->in = open(iter->cmd, O_RDWR);
	if (tokens->in == -1 && tokens->err != 1)
	{
		perror(iter->cmd);
		g_exit_status = 1;
	}
}

void	ft_cmd_clear(t_a9aw9o3 **cmd, t_pars *p)
{
	t_heredoc	*tmp_herdoc;
	t_a9aw9o3	*head;
	t_a9aw9o3	*tmp;
	t_heredoc	*her;

	her = p->her_head;
	while (her)
	{
		tmp_herdoc = her;
		her = her->next;
		free(tmp_herdoc);
	}
	head = *cmd;
	while (head)
	{
		tmp = head;
		free(head->cmd);
		head = head->next;
		free(tmp);
	}
	free(p);
}

int	get_qoutes(char *str, int index)
{
	int	quotes;
	int	i;

	i = 0;
	quotes = 0;
	while (i < index && str[i])
	{
		if (str[i] == 39 && quotes < 1)
			quotes = 1;
		else if (str[i] == 34 && quotes < 1)
			quotes = 2;
		else if (str[i] == 39 && quotes == 1)
			quotes = 0;
		else if (str[i] == 34 && quotes == 2)
			quotes = 0;
		++i;
	}
	return (quotes);
}

int	is_exp(char *buff)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '$' && buff[i + 1] != '\'' && buff[i + 1] != '\"'
			&& is_alphanum(buff[i + 1]) && get_qoutes(buff, i) != 1)
			return (1);
		++i;
	}
	return (0);
}
