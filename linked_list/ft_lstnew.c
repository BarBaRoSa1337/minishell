/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:41:03 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/04 17:41:04 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_ms	*ft_lstnew(void)
{
	t_ms	*new_node;

	new_node = (t_ms *)malloc(sizeof(t_ms));
	if (!new_node)
		return (0);
	new_node->infile = 0;
	new_node->cmd = NULL;
	new_node->arg = NULL;
	new_node->outfile = 1;
	new_node->next = NULL;
	new_node->error = 0;
	return (new_node);
}
