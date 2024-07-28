/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:31:02 by csaidi            #+#    #+#             */
/*   Updated: 2023/12/14 10:04:15 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;
	size_t	j;

	if (!dst && !dstsize)
		return (ft_strlen(src));
	len = ft_strlen(dst);
	if (dstsize <= len)
		return (ft_strlen(src) + dstsize);
	i = 0;
	j = len;
	while (src[i] && i < dstsize - (len + 1))
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (len + ft_strlen(src));
}
