/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:46:28 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/10 16:45:10 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_args(t_arg **arg)
{
	t_arg	*head;
	t_arg	*tmp;

	if (!arg || !(*arg))
		return ;
	head = (*arg);
	while (head)
	{
		free(head->arg);
		head = head->next;
	}
	head = *arg;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void	free_shell(t_shell **shell)
{
	t_shell	*tmp;
	t_shell	*head;

	if (!shell || !(*shell))
		return ;
	head = *shell;
	while (head)
	{
		tmp = head;
		free(head->cmd);
		free_args(&head->args);
		head = head->next;
		free(tmp);
	}
}

void	free_ms(t_ms **ms)
{
	t_ms	*tmp;
	t_ms	*head;

	if (!ms || !(*ms))
		return ;
	head = *ms;
	while (head)
	{
		tmp = head;
		free(head->cmd);
		if (head->arg)
			ft_free(head->arg);
		head = head->next;
		free(tmp);
	}
}

void	free_env(t_env **v)
{
	t_env	*tmp;
	t_env	*head;

	if (!v || !(*v))
		return ;
	head = (*v);
	while (head)
	{
		tmp = head;
		free(head->key);
		free(head->value);
		head = head->next;
		free(tmp);
	}
}
