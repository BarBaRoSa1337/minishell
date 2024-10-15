/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:54:09 by achakour          #+#    #+#             */
/*   Updated: 2024/09/10 12:12:50 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_back_9aw9a3a(t_a9aw9o3 **lst, t_a9aw9o3 *new)
{
	t_a9aw9o3	*head;

	if (!new || lst == NULL)
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

t_a9aw9o3	*lstnew_9aw9a3a(char *arg, int quote_type)
{
	t_a9aw9o3	*node;

	node = malloc(sizeof(t_a9aw9o3));
	if (!node)
		return (NULL);
	node->quoted = quote_type;
	node->next = NULL;
	node->cmd = arg;
	node->err = 0;
	return (node);
}

t_a9aw9o3	*lstnew_exp(char *arg)
{
	t_a9aw9o3	*node;

	node = malloc(sizeof(t_a9aw9o3));
	if (!node)
		return (NULL);
	node->cmd = ft_strdup(arg);
	node->next = NULL;
	node->type = 2;
	node->err = 2;
	return (node);
}

char	*ft_strjoin_exp(char *s1, char *s2)
{
	size_t	buffer_size;
	char	*buffer;
	size_t	s1len;
	size_t	s2len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	buffer_size = s1len + s2len + 1;
	buffer = (char *)malloc(buffer_size);
	if (!buffer)
	{
		return (free(s1), NULL);
	}
	ft_strlcpy(buffer, s1, buffer_size);
	ft_strlcpy(buffer + s1len, s2, buffer_size);
	return (free(s1), buffer);
}

// void	ft_cmd_clear2(t_pars *p)
// {
// 	t_shell	*tok;
// 	t_shell	*tmp;

// 	// tok = p->tokens;
// 	// while (tok)
// 	// {
// 	// 	tmp = tok;
// 	// 	tok = tok->next;
// 	// 	free (tmp);
// 	// }
// 	free(p);
// }
