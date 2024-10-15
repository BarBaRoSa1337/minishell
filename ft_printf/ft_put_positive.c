/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_positive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:37:23 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/04 17:37:26 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_put_positive(unsigned int c, int len)
{
	if (c >= 10)
	{
		len = ft_putnbr(c / 10, len);
		len = ft_putchar(c % 10 + 48, len);
	}
	else if (c < 10)
		len = ft_putchar(c + 48, len);
	return (len);
}
