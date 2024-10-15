/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_searsh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:45:36 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/11 10:17:19 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*env_searsh(t_env *v, char *find)
{
	if (!v)
		return (NULL);
	while (v)
	{
		if (ft_strncmp(v->key, find, sizeof(v->key)) == 0)
		{
			if (!v->value)
				return ("ignore");
			return (v->value);
		}
		v = v->next;
	}
	return (NULL);
}
