/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:45:43 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/09 09:45:19 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_env(t_env *v)
{
	int	i;

	i = 0;
	while (v)
	{
		if (v->value)
			i++;
		v = v->next;
	}
	return (i);
}

char	**env_to_ptr(t_env *v)
{
	char	**ptr;
	char	*res;
	int		i;

	i = 0;
	if (!v)
		return (NULL);
	ptr = malloc((count_env(v) + 1) * sizeof(char *));
	while (v)
	{
		if (v->value)
		{
			res = ft_strjoin(v->key, "=");
			ptr[i] = ft_strjoin(res, v->value);
			free(res);
			i++;
		}
		v = v->next;
	}
	ptr[i] = NULL;
	return (ptr);
}
