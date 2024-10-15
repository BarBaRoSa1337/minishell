/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:55:09 by achakour          #+#    #+#             */
/*   Updated: 2024/09/12 23:39:56 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_shell	*tokens_new(void)
{
	t_shell	*new;

	new = malloc(sizeof(t_shell));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->args = NULL;
	new->cmd = NULL;
	new->err = 0;
	new->out = 1;
	new->in = 0;
	return (new);
}

t_arg	*arg_new(char *cmd)
{
	t_arg	*new;

	new = malloc(sizeof(t_arg));
	if (!new)
		return (NULL);
	new->arg = ft_strdup(cmd);
	new->next = NULL;
	return (new);
}

void	lst_rje3_lor(t_arg **lst, t_arg *new)
{
	t_arg	*head;

	if (!new || !lst)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	head = *lst;
	while (head->next != NULL)
		head = head->next;
	head->next = new;
}

void	free_exp(char **buff)
{
	int	i;

	i = -1;
	while (*buff && buff[++i])
		free(buff[i]);
	free(buff);
}

int	space_exp(char *exp)
{
	int	i;

	i = 0;
	while (exp && (exp[i] == ' ' || exp[i] == '\t'))
		++i;
	if (exp && exp[i] && (is_alphanum(exp[i]) || ft_strchr("\"\'", exp[i]))
		&& ft_strchr(exp, ' '))
		return (1);
	return (0);
}
