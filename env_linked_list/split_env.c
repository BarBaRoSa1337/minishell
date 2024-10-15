/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:14:45 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/08 13:07:42 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	loop_into(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

t_env	*split_env(char *str, int i, int j)
{
	t_env	*new;

	new = env_lstnew();
	i = loop_into(str, '=');
	new->key = malloc(i + 1);
	i = 0;
	j = 0;
	while (str[i] && str[i] != '=')
		new->key[j++] = str[i++];
	new->key[j] = '\0';
	if (str[i] == '=' && str[i + 1])
	{
		i++;
		j = 0;
		while (str[i + j])
			j++;
		new->value = malloc(j + 1);
		ft_strlcpy(new->value, str + i, j + 1);
	}
	else
		new->value = NULL;
	return (new);
}
