/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:31:06 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/06 15:46:04 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	i;

	srclen = ft_strlen(src);
	if (dstsize != 0)
	{
		i = 0;
		while (*(src + i) != '\0' && --dstsize)
		{
			*(dst + i) = *(src + i);
			++i;
		}
		*(dst + i) = '\0';
	}
	return (srclen);
}
