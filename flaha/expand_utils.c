/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:17:40 by achakour          #+#    #+#             */
/*   Updated: 2024/09/12 11:48:29 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_get_str(char *str, int len)
{
	char	*buff;
	int		i;

	if (!str)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (len + 1));
	if (!buff)
		return (NULL);
	i = 0;
	while (i < len)
	{
		buff[i] = str[i];
		++i;
	}
	buff[i] = '\0';
	return (buff);
}

char	*ft_strjoin_ex(char *s1, char *s2)
{
	size_t	buffer_size;
	char	*buffer;

	buffer_size = (ft_strlen(s1) + ft_strlen(s2) + 1);
	buffer = (char *)malloc(buffer_size);
	if (!buffer)
	{
		return (NULL);
	}
	ft_strlcpy(buffer, s1, buffer_size);
	ft_strlcat(buffer, s2, buffer_size);
	free(s1);
	return (buffer);
}

char	*get_env(char *buff, t_env *env)
{
	t_env	*p;

	p = env;
	while (p)
	{
		if (ft_strncmp(buff, p->key, sizeof(buff)) == 0)
			return (ft_strdup(p->value));
		p = p->next;
	}
	return (NULL);
}

int	is_alphanum(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0'
			&& c <= '9') || c == '?')
		return (1);
	return (0);
}

void	handle_space_exp(t_a9aw9o3 *lst, t_a9aw9o3 *next_node, char *str)
{
	t_pars	s;

	s.i = 0;
	s.j = 0;
	s.head = NULL;
	s.buffer = exp_split(str);
	if (is_join(lst->cmd) == 0)
		lst->cmd = ft_strjoin_exp(get_4_join(lst->cmd), s.buffer[s.i]);
	else
		lst->cmd = ft_strdup(s.buffer[s.i]);
	if (ft_strchar(str, "\"\'"))
		lst->err = 2;
	if (!s.buffer[s.i + 1])
	{
		free_exp(s.buffer);
		return ;
	}
	while (s.buffer[++s.i])
		add_back_9aw9a3a(&s.head, lstnew_exp(s.buffer[s.i]));
	lst->next = s.head;
	while (s.head->next)
		s.head = s.head->next;
	s.head->next = next_node;
	free_exp(s.buffer);
}
