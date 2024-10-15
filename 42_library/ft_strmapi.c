/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:13:40 by csaidi            #+#    #+#             */
/*   Updated: 2024/08/20 12:08:01 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	unsigned int	size;
	unsigned int	i;
	char			*ptr;

	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	ptr = malloc(size + 1 * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
