/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_unset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:27:02 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/10 02:09:51 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_node(t_env *v)
{
	if (v->key)
		free(v->key);
	if (v->value)
		free(v->value);
	if (v)
		free(v);
}

void	delete_first(t_env **v, t_env *tmp)
{
	(*v) = (*v)->next;
	free_node(tmp);
}

void	delete_normal(t_env *head, t_env *tmp)
{
	tmp->next = head->next;
	free_node(head);
}

int	check_str(char **str, t_env **v)
{
	if (!(*v) || !v)
		return (-1);
	if (!str)
	{
		g_exit_status = 0;
		return (1);
	}
	if (str[0][0] == '-')
	{
		ft_printf("unset: %c: invalid option\n", str[0][0]);
		g_exit_status = 2;
		return (-1);
	}
	g_exit_status = 0;
	return (1);
}

void	build_unset(char **str, t_env **v, int i)
{
	t_env	*head;
	t_env	*tmp;

	if (check_str(str, v) != -1)
	{
		while (str[i])
		{
			head = (*v);
			tmp = head;
			while (head)
			{
				if (ft_strncmp(str[i], head->key, sizeof(str[i])) == 0)
				{
					if (tmp == head)
						delete_first(v, tmp);
					else
						delete_normal(head, tmp);
					break ;
				}
				tmp = head;
				head = head->next;
			}
			i++;
		}
	}
}
