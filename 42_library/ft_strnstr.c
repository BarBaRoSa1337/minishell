/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:31:18 by csaidi            #+#    #+#             */
/*   Updated: 2024/08/20 12:08:01 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strnstr(char *haystack, char *needle, size_t len)
{
	size_t	size;

	size = 0;
	if ((!haystack || !needle) && len == 0)
		return (0);
	while (needle[size] != '\0' && size <= len)
		size++;
	if (size == 0)
		return ((char *)haystack);
	while (*haystack != '\0' && len >= size)
	{
		if (*needle == *haystack && ft_strncmp(haystack, needle, size) == 0)
		{
			return ((char *)haystack);
		}
		haystack++;
		len--;
	}
	return (0);
}
