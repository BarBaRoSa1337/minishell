/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_pwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:26:49 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/06 16:24:39 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count(char **ptr)
{
	int	l;

	l = 0;
	while (ptr[l])
		l++;
	if (l > 1)
	{
		printf("too many arguments\n");
		g_exit_status = 1;
		return (-1);
	}
	return (1);
}

int	check_ptr(char **ptr)
{
	if (!ptr)
		return (1);
	if (count(ptr) == -1)
		return (-1);
	if (ptr[0][0] == '-')
	{
		if (ptr[0][1])
			ft_printf("pwd: %c%c: invalid option\n", ptr[0][0], ptr[0][1]);
		else
			ft_printf("pwd: %c: invalid option\n", ptr[0][0]);
		g_exit_status = 2;
		return (-1);
	}
	return (1);
}

void	build_pwd(char **ptr)
{
	char	path[PATH_SIZE];

	if (check_ptr(ptr) == -1)
		return ;
	if (getcwd(path, sizeof(path)) == NULL)
		perror("Error");
	ft_putstr_fd(path, 1);
	ft_putchar_fd('\n', 1);
	g_exit_status = 0;
	return ;
}
