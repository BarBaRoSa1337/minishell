/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:42:07 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/11 09:49:15 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	update_env(t_env **env, char *key, char *new_value)
{
	t_env	*head;

	head = (*env);
	while (head)
	{
		if (ft_strncmp(key, head->key, sizeof(key)) == 0)
		{
			free(head->value);
			head->value = ft_strdup(new_value);
			return ;
		}
		head = head->next;
	}
}
