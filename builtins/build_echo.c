/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:26:32 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/08 12:50:10 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	its_n(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	else
		return (-1);
	while (str[i])
	{
		if (str[i] == 'n')
			i++;
		else
			return (-1);
	}
	return (1);
}

void	print_str(char **arg, int i, int fd, int nl)
{
	while (arg[i])
	{
		ft_putstr_fd(arg[i], fd);
		if (arg[i + 1])
			ft_putchar_fd(' ', fd);
		i++;
	}
	if (nl == 1)
		ft_putchar_fd('\n', fd);
}

void	build_echo(char **arg, int fd)
{
	int	i;
	int	nl;

	i = 0;
	nl = 1;
	g_exit_status = 0;
	if (!arg || !arg[0])
		ft_putstr("\n", fd);
	else
	{
		while (arg[i])
		{
			if (i == 0 && arg[0][0] == '-' && its_n(arg[0]) == 1)
			{
				nl = 0;
				i++;
			}
			else if (arg[i][0] == '-' && its_n(arg[i]) == 1)
				i++;
			else
				break ;
		}
		print_str(arg, i, fd, nl);
	}
}
