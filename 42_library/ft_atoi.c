/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:29:27 by csaidi            #+#    #+#             */
/*   Updated: 2023/12/17 13:11:20 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

int	convert_ascii(const char *str, int i)
{
	int	n;

	n = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - 48);
		i++;
	}
	return (n);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		l;
	int		result;

	i = 0;
	l = 1;
	if (!str[0] || !str)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ' || str[i] == 0)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9')
		{
			l = -1;
			i++;
		}
		else if (str[i] == '+' && str[i + 1] >= '0' && str[i + 1] <= '9')
			i++;
		else
			return (0);
	}
	result = convert_ascii(str, i);
	return (result * l);
}
