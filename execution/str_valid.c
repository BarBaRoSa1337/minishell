/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:47:26 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/04 17:48:43 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	valid_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0'
			&& c <= '9') || c == '_')
		return (1);
	else
		return (-1);
}

int	exep_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0'
			&& c <= '9') || c == '=' || c == '+' || c == '_')
		return (1);
	else
		return (-1);
}

int	str_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (exep_alpha(str[i]) != -1)
			i++;
		else
			return (-1);
	}
	return (1);
}
