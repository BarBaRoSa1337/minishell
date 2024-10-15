/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:26:35 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/10 16:50:32 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	build_env(t_env *v, char **ptr)
{
	t_env	*head;

	head = v;
	if (!ptr)
	{
		while (head)
		{
			if (head->value != NULL)
			{
				ft_putstr_fd(head->key, 1);
				ft_putchar_fd('=', 1);
				ft_putstr_fd(head->value, 1);
				ft_putchar_fd('\n', 1);
			}
			head = head->next;
		}
		g_exit_status = 0;
	}
	else
	{
		ft_printf("env: %s: No such file or directory", ptr[0]);
		g_exit_status = 127;
	}
	return ;
}
