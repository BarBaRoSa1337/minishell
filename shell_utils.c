/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:54:09 by achakour          #+#    #+#             */
/*   Updated: 2024/07/28 10:11:09 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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

void	print(char *str, int i)
{
	int j = 0;

	while (j < i)
	{
		printf("%c", str[j]);
		++j;
	}
}

char	*ft_strjoin_exp(char *s1, char *s2, int index)
{
	size_t	buffer_size;
	char	*buffer;
	size_t	s1len;
	size_t	s2len;

	if (!s1 || !s2)
	{
		return (NULL);
	}
	s1len = index;
	s2len = ft_strlen(s2);
	buffer_size = s1len + s2len + 1;
	buffer = (char *)malloc(buffer_size);
	if (!buffer)
	{
		return (NULL);
	}
	ft_strlcpy(buffer, s1, s1len);
	ft_strlcpy(buffer + s1len, s2, buffer_size);
	// free (s1);
	// free (s2);
	return (buffer);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	buffer_size;
	char	*buffer;
	size_t	s1len;
	size_t	s2len;

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
	ft_strlcpy(buffer, s1, s1len);
	ft_strlcpy(buffer + s1len, s2, buffer_size);
	// free (s1);
	// free (s2);
	return (buffer);
}