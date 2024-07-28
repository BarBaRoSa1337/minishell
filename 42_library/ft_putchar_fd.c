/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:34:56 by csaidi            #+#    #+#             */
/*   Updated: 2023/12/14 16:36:17 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../execution.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int main()
// {
// 	// int b = open("tesst", O_CREAT | O_RDWR);
// 	// //ft_putchar_fd('b', b);
// 	// close(b);
// 	ft_putchar_fd('b', 2);
// }