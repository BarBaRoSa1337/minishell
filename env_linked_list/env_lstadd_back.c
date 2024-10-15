/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:14:33 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/09 10:20:23 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	env_lstadd_back(t_env **lst, t_env *new)
{
	t_env	*last;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	last = env_lstlast(*lst);
	last->next = new;
}
