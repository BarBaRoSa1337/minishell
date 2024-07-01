/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:31:18 by csaidi            #+#    #+#             */
/*   Updated: 2023/12/17 13:19:00 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	size;

	size = 0;
	if ((!haystack || !needle) && len == 0)
		return (0);
	while (needle[size] != '\0' && size <= len)
		size++;
	if (size == 0)
		return ((char *) haystack);
	while (*haystack != '\0' && len >= size)
	{
		if (*needle == *haystack && ft_strncmp(haystack, needle, size) == 0)
		{
			return ((char *) haystack);
		}
		haystack++;
		len--;
	}
	return (0);
}
