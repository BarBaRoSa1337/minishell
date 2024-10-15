/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:31:13 by csaidi            #+#    #+#             */
/*   Updated: 2024/08/20 12:08:01 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	if (!s1)
		return (-1);
	i = 0;
	if (n == 0)
		return (0);
	while ((unsigned char)s2[i] == (unsigned char)s1[i] && (unsigned char)s1[i]
		&& (unsigned char)s2[i] && i + 1 < n)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
