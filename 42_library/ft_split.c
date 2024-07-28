/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:13:07 by csaidi            #+#    #+#             */
/*   Updated: 2023/12/17 13:12:26 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../execution.h"

int	ft_count(const char *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (s == 0)
		return (0);
	if (s[0] != c && s[0])
		count++;
	while (i < (int)ft_strlen(s))
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			count++;
		i++;
	}
	return (count);
}

static	char	*ft_copysubstr(char *s, int len, int i)
{
	char	*little;
	int		j;

	little = malloc((i - len + 1) * sizeof(char));
	if (!little)
		return (NULL);
	j = 0;
	while (len < i)
	{
		little[j++] = s[len++];
	}
	little[j] = '\0';
	return (little);
}

static void	*ft_free_memory(char **ptr, int l)
{
	while (l >= 0)
	{
		free (ptr[l]);
		l--;
	}
	free (ptr);
	return (NULL);
}

char	**ft_alloc(char *s, char c, char **ptr)
{
	int	i;
	int	l;
	int	len;

	i = 0;
	l = 0;
	len = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			ptr[l++] = ft_copysubstr(s, len, i);
			if (!ptr)
				return (ft_free_memory(ptr, l));
			while (s[i] == c)
				i++;
			len = i;
		}
		i++;
	}
	ptr[l] = ft_copysubstr(s, len, i);
	if (!ptr)
		return (ft_free_memory(ptr, l));
	free(s);
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**ptr;
	char	*s_trim;
	char	sep[2];

	sep[0] = c;
	sep[1] = '\0';
	s_trim = ft_strtrim(s, sep);
	if (!s_trim)
		return (0);
	if (!s_trim[0])
	{
		free(s_trim);
		ptr = malloc((1) * sizeof(char *));
		ptr[0] = NULL;
		return (ptr);
	}
	count = ft_count((char *)s_trim, c);
	ptr = malloc((count + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	ptr[count] = NULL;
	return (ft_alloc((char *)s_trim, c, ptr));
}
