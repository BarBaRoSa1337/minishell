/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:30:30 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/06 12:39:58 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strchr(char *s, int c)
{
	size_t	l;
	char	*str;

	l = 0;
	if (!s)
		return (NULL);
	str = (char *)s;
	while (str[l] != '\0')
	{
		if ((char)c == str[l])
			return (&str[l]);
		else
			l++;
	}
	return (NULL);
}
