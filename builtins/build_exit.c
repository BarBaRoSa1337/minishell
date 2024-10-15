/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:26:42 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/04 17:29:12 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	its_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && (str[i] == '+' || str[i] == '-'))
			i++;
		else if (str[i] >= 48 && str[i] <= 57)
			i++;
		else
			return (-1);
	}
	return (0);
}

void	build_exit(char **status)
{
	if (!status || !status[0])
		exit(0);
	else if (multiple_arg(status) != -1)
	{
		ft_printf("exit: too many arguments\n");
		g_exit_status = 1;
	}
	else if (its_num(status[0]) == -1)
	{
		ft_printf("exit: %s: numeric argument required\n", status[0]);
		g_exit_status = 2;
		exit(2);
	}
	else if (its_num(status[0]) == 0)
	{
		g_exit_status = ft_atoi(status[0]);
		exit(ft_atoi(status[0]));
	}
}
