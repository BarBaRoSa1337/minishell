/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:31:21 by csaidi            #+#    #+#             */
/*   Updated: 2024/08/20 12:05:45 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strrchr(char *s, int c)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = ft_strlen(s);
	while (i)
	{
		if (str[i] == (char)c)
			return (&str[i]);
		else
			i--;
	}
	if (str[i] == (char)c)
		return (&str[i]);
	return (NULL);
}
