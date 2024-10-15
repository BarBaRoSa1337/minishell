/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_to_hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:37:03 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/04 17:37:07 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_decimal_to_hex(unsigned long decimal, int len)
{
	char	*hexnbr;

	hexnbr = "0123456789abcdef";
	if (decimal < 16)
		len = ft_putchar(hexnbr[decimal % 16], len);
	else if (decimal >= 16)
	{
		len = ft_decimal_to_hex(decimal / 16, len);
		len = ft_putchar(hexnbr[decimal % 16], len);
	}
	return (len);
}
