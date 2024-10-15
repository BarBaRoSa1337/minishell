/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:27:08 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/11 10:24:49 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_valid(char *s, int i)
{
	while (s[i] && s[i] != '+' && s[i] != '=')
	{
		if (i == 0)
		{
			if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')
				|| s[i] == '_')
				i++;
			else
				return (-1);
		}
		else if (valid_alpha(s[i]) == 1)
			i++;
		else
			return (-1);
	}
	if (s[i])
	{
		if (s[i] == '+' && valid_alpha(s[i - 1]) == 1 && s[i + 1] == '=')
			return (1);
		else if (s[i] == '=' && (valid_alpha(s[i - 1]) == 1 || s[i - 1] == '+'))
			return (1);
		else
			return (-1);
	}
	return (1);
}

int	join_value(t_env **v, char *key, char *new_value)
{
	t_env	*head;
	char	*tmp;

	head = (*v);
	while (head)
	{
		if (ft_strncmp(head->key, key, sizeof(head->key)) == 0)
		{
			tmp = ft_strjoin(head->value, new_value);
			free(head->value);
			head->value = tmp;
			return (0);
		}
		head = head->next;
	}
	return (-1);
}

char	*take_new(char *str)
{
	int		i;
	char	*key;

	i = 0;
	while (str[i] && str[i] != '=' && str[i] != '+')
		i++;
	key = malloc(i + 1);
	key[i] = '\0';
	i = 0;
	while (str[i] && str[i] != '=' && str[i] != '+')
	{
		key[i] = str[i];
		i++;
	}
	return (key);
}

char	*take_value(char *str)
{
	int		i;
	int		j;
	char	*value;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (str[i] == '=')
	{
		j = 0;
		while (str[i++])
			j++;
		value = malloc(j);
		i = i - j;
		j = 0;
		while (str[i])
			value[j++] = str[i++];
		value[j] = '\0';
	}
	else
		value = NULL;
	return (value);
}

t_env	*export_split(char *str, t_env **v)
{
	t_env	*new;

	new = env_lstnew();
	if (is_valid(str, 0) == -1)
	{
		ft_printf("export: %s: not a valid identifier\n", str);
		g_exit_status = 1;
		return (free(new), NULL);
	}
	new->key = take_new(str);
	new->value = take_value(str);
	if (env_searsh((*v), new->key) && !ft_strchr(str, '+') && new->value)
		update_value(v, new);
	else if (env_searsh((*v), new->key) && ft_strchr(str, '+') && new->value)
		join_value(v, new->key, new->value);
	else if (!env_searsh((*v), new->key))
	{
		env_lstadd_back(v, new);
		g_exit_status = 0;
		return (new);
	}
	g_exit_status = 0;
	return (free(new->key), free(new->value), free(new), NULL);
}
