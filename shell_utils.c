/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:54:09 by achakour          #+#    #+#             */
/*   Updated: 2024/07/17 10:20:30 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstadd_back(t_a9aw9o3 **lst, t_a9aw9o3 *new)
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

t_a9aw9o3	*ft_lstnew(char *arg, int quote_type)
{
	t_a9aw9o3	*node;

	node = malloc(sizeof(t_a9aw9o3));
	if (!node)
		return (NULL);
	node->cmd = arg;
	node->quoted = quote_type;
	node->next = NULL;
	return (node);
}

int	check(char c, char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		++i;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*buff;
	size_t	start;
	size_t	end;

	end = ft_strlen(s1);
	start = 0;
	while (check(s1[start], (char *)set) && start < end)
		++start;
	--end;
	while (check(s1[end], (char *)set) && end > start)
		--end;
	++end;
	buff = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!buff)
		return (NULL);
	ft_strlcpy(buff, (char *)s1 + start, end - start + 1);
	return (buff);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	buffer_size;
	size_t	s1len;
	size_t	s2len;
	char	*buffer;

	if (!s1 || !s2)
	{
		return (NULL);
	}
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	buffer_size = s1len + s2len + 1;
	buffer = (char *)malloc(buffer_size);
	if (!buffer)
	{
		return (NULL);
	}
	ft_strlcpy(buffer, (char *)s1, buffer_size);
	ft_strlcpy(buffer + s1len, (char *)s2, buffer_size);
	return (buffer);
}