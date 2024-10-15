/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:26:45 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/10 17:23:42 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	build_export(char **str, t_env **v)
{
	t_env	*head;
	int		i;

	i = 0;
	if (str && str[i])
	{
		while (str[i])
		{
			export_split(str[i], v);
			i++;
		}
	}
	else
	{
		head = make_copy(*v);
		get_order(head);
		print_copy(head);
		free_env(&head);
		g_exit_status = 0;
	}
	return ;
}
