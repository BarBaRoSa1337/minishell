/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:36:58 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/04 17:36:59 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_check(char s, va_list args, int len)
{
	if (s == 'c')
		len = ft_putchar(va_arg(args, int), len);
	else if (s == '%')
		len = ft_putchar('%', len);
	else if (s == 's')
		len = ft_putstr(va_arg(args, char *), len);
	else if (s == 'd' || s == 'i')
		len = ft_putnbr(va_arg(args, int), len);
	else if (s == 'u')
		len = ft_put_positive(va_arg(args, unsigned int), len);
	else if (s == 'x')
		len = ft_decimal_to_hex(va_arg(args, unsigned int), len);
	else if (s == 'X')
		len = ft_decimal_to_hexa(va_arg(args, unsigned int), len);
	else if (s == 'p')
		len = ft_put_adress(va_arg(args, unsigned long), len);
	return (len);
}
