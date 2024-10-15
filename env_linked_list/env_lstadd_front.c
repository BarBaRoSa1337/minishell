/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:14:27 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/04 17:14:28 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	env_lstadd_front(t_env **lst, t_env *new)
{
	if (!lst)
		return ;
	if (*lst)
		new->next = *lst;
	*lst = new;
}
