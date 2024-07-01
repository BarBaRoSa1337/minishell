/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:12:39 by csaidi            #+#    #+#             */
/*   Updated: 2023/12/05 21:45:48 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../minishell.h"

int	countint(int n)
{
	int	i;

	if (n == 0)
		return (1);
	if (n < 0)
	{
		i = 1;
	}
	else
		i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_remply(char *str, int size, int n)
{
	int	i;

	i = 0;
	str[size] = '\0';
	if (n == -2147483648)
	{
		str[size - 1] = '8';
		size--;
		n = n / 10;
	}
	if (n < 0)
	{
		str[i] = '-';
		i++;
		n = n * -1;
	}
	while (i < size)
	{
		str[size - 1] = n % 10 + '0';
		n = n / 10;
		size--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*str;

	size = countint(n);
	str = malloc(size + 1 * sizeof(char));
	if (!str)
		return (0);
	return (ft_remply(str, size, n));
}
