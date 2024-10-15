/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:16:47 by achakour          #+#    #+#             */
/*   Updated: 2024/09/12 16:29:06 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_charchr(char c, char *find)
{
	int	i;

	if (!find)
		return (0);
	i = 0;
	while (find[i])
	{
		if (find[i] == c)
			return (1);
		++i;
	}
	return (0);
}

int	ft_strchar(char *s, char *find)
{
	int	i;
	int	j;

	i = 0;
	if (!find)
		return (0);
	while (s[i])
	{
		j = 0;
		while (find[j])
		{
			if (s[i] == find[j])
				return (1);
			++j;
		}
		++i;
	}
	return (0);
}

int	is_join(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '$' && str[i] != ' ' && str[i] != '\t')
		return (0);
	return (1);
}

char	*get_4_join(char *str)
{
	char	*buff;
	int		i;

	i = 0;
	while (str[i] != '$')
		++i;
	buff = (char *)malloc(sizeof(char) * i + 1);
	if (!buff)
		return (NULL);
	i = -1;
	while (str && str[++i] != '$')
		buff[i] = str[i];
	buff[i] = '\0';
	return (buff);
}
