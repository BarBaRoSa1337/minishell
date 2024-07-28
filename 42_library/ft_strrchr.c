/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:31:21 by csaidi            #+#    #+#             */
/*   Updated: 2023/12/01 10:54:12 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

char	*ft_strrchr(const char *s, int c)
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
