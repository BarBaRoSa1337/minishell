/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:31:02 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/04 17:36:37 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstlen >= dstsize)
	{
		return (srclen + dstsize);
	}
	if (0 < dstsize - dstlen - 1)
	{
		ft_strlcpy(dst + dstlen, src, dstsize - dstlen);
	}
	return (dstlen + srclen);
}
