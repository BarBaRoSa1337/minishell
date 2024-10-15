/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:14:42 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/11 09:39:13 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_shlvl(t_env **env)
{
	t_env	*head;
	char	*tmp;

	head = (*env);
	while (head)
	{
		if (ft_strncmp(head->key, "SHLVL", sizeof(head->key)) == 0)
		{
			tmp = ft_itoa(ft_atoi(head->value) + 1);
			free(head->value);
			head->value = tmp;
			break ;
		}
		head = head->next;
	}
	return ;
}

void	get_envp(char **envp, t_env **head)
{
	t_env	*new;
	int		l;

	if (!envp)
		return ;
	l = 0;
	while (envp[l])
	{
		new = split_env(envp[l], 0, 0);
		env_lstadd_back(head, new);
		l++;
	}
	add_shlvl(head);
	return ;
}
