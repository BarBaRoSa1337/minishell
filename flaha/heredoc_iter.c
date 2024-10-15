/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_iter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:56:34 by achakour          #+#    #+#             */
/*   Updated: 2024/09/12 15:52:05 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_heredoc	*lstlast(t_heredoc *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_heredoc	*lstnew(void)
{
	t_heredoc	*new_node;

	new_node = (t_heredoc *)malloc(sizeof(t_heredoc));
	if (!new_node)
		return (0);
	new_node->fd = 0;
	new_node->next = NULL;
	return (new_node);
}

void	lst_addback(t_heredoc **lst, t_heredoc *new)
{
	t_heredoc	*last;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	last = lstlast(*lst);
	last->next = new;
}

t_heredoc	*heredoc_iter(t_a9aw9o3 *head, t_env *env)
{
	t_heredoc	*first;
	t_heredoc	*new;

	first = NULL;
	while (head)
	{
		if (head->type == 6 && !ft_strchar(head->cmd, "<<"))
		{
			new = lstnew();
			new->fd = ft_heredoc(head->cmd, env, head->quoted);
			lst_addback(&first, new);
		}
		head = head->next;
	}
	return (first);
}
