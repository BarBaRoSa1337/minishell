/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:09:28 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/11 10:40:11 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free(char **ptr)
{
	int	l;

	if (!ptr || !ptr[0])
		return ;
	l = 0;
	while (ptr[l])
	{
		free(ptr[l]);
		l++;
	}
	free(ptr);
}

int	multiple_arg(char **ptr)
{
	int	l;

	l = 0;
	while (ptr[l])
		l++;
	if (l > 1)
		return (1);
	return (-1);
}
