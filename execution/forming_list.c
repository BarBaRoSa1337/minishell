/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forming_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:46:22 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/12 12:12:07 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	nbr_of_arg(t_arg *p)
{
	int	i;

	i = 0;
	while (p)
	{
		i++;
		p = p->next;
	}
	return (i);
}

char	**get_args(t_arg *p, char *cmd)
{
	char	**args;
	int		len;

	if (!p)
		return (NULL);
	len = nbr_of_arg(p);
	len++;
	args = malloc((len + 1) * sizeof(char *));
	args[len] = NULL;
	args[0] = ft_strdup(cmd);
	len = 1;
	while (p)
	{
		args[len] = ft_strdup(p->arg);
		p = p->next;
		len++;
	}
	return (args);
}

t_ms	*forming_list(t_shell *shell, int i)
{
	t_shell	*tmp;
	t_ms	*new;
	t_ms	*head;

	if (!shell)
		return (NULL);
	new = ft_lstnew();
	head = new;
	tmp = shell;
	while (tmp)
	{
		head->pid = i++;
		head->cmd = ft_strdup(tmp->cmd);
		head->infile = tmp->in;
		head->outfile = tmp->out;
		head->error = tmp->err;
		head->arg = get_args(tmp->args, head->cmd);
		if (tmp->next)
		{
			ft_lstadd_back(&new, ft_lstnew());
			head = head->next;
		}
		tmp = tmp->next;
	}
	return (free_shell(&shell), new);
}
