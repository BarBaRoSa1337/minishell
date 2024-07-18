/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:16:47 by achakour          #+#    #+#             */
/*   Updated: 2024/07/17 18:16:58 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strdup(const char *str)
{
	char	*p;
	int		len;

	len = ft_strlen(str);
	p = (char *)malloc(sizeof(char) * len + 1);
	if (p == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(p, (char *)str, len + 1);
	return (p);
}

int	ft_charchr(char c, char *find)
{
	int	i;

	i = 0;
	while (find[i])
	{
		if (find[i] == c)
			return (1);
		++i;
	}
	return(0);
}

int	ft_strchr(char *s, char *find)
{
	int			i;
	int			j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (find[j])
		{
			if (s[i] == find[j])
				return (0);
			++j;
		}
		++i;
	}
	return(1);
}

size_t	ft_strlen(const char *str)
{
	const char	*p;

	p = str;
	while (*p)
		++p;
	return (p - str);
}

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*sub;

	if (s == NULL)
	{
		return (NULL);
	}
	slen = ft_strlen(s);
	if (start >= slen)
	{
		sub = malloc(1);
		sub[0] = '\0';
		return (sub);
	}
	if (len > slen)
	{
		len = ft_strlen(s + start);
	}
	sub = (char *)malloc(sizeof(char) * len + 1);
	if (!sub)
	{
		return (NULL);
	}
	ft_strlcpy(sub, (char *)s + start, len + 1);
	return (sub);
}
