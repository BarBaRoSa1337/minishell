/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:27:13 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/10 17:23:19 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	swap(t_env *v)
{
	char	*tmp;
	char	*tmp2;

	if (!v || !v->next)
		return ;
	tmp2 = NULL;
	tmp = v->next->key;
	if (v->next->value)
		tmp2 = v->next->value;
	v->next->key = v->key;
	v->next->value = v->value;
	v->key = tmp;
	v->value = tmp2;
}

void	get_order(t_env *v)
{
	t_env	*head;
	t_env	*head2;

	head = v;
	while (head)
	{
		head2 = head;
		while (head2)
		{
			if (head2->next && ft_strcmp(head2->key, head2->next->key) > 0)
			{
				swap(head2);
				head2 = head;
			}
			else
				head2 = head2->next;
		}
		head = head->next;
	}
}

void	print_copy(t_env *v)
{
	t_env	*head;

	head = v;
	while (head)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(head->key, 1);
		if (head->value)
		{
			ft_putchar_fd('=', 1);
			ft_putchar_fd('"', 1);
			ft_putstr_fd(head->value, 1);
			ft_putchar_fd('"', 1);
		}
		ft_putchar_fd('\n', 1);
		head = head->next;
	}
}

t_env	*make_copy(t_env *v)
{
	t_env	*head;
	t_env	*iter;
	t_env	*new;

	iter = v;
	head = NULL;
	while (iter)
	{
		new = env_lstnew();
		new->key = ft_strdup(iter->key);
		new->value = ft_strdup(iter->value);
		env_lstadd_back(&head, new);
		iter = iter->next;
	}
	return (head);
}

void	update_value(t_env **v, t_env *new)
{
	t_env	*head;

	head = (*v);
	while (head)
	{
		if (ft_strncmp(new->key, head->key, sizeof(new->key)) == 0)
		{
			if (head->value)
			{
				free(head->value);
				head->value = NULL;
			}
			if (new->value)
				head->value = ft_strdup(new->value);
			return ;
		}
		head = head->next;
	}
	return ;
}
