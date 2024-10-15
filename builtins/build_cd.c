/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:26:28 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/08 15:46:52 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_arg(char **ptr)
{
	int	l;

	l = 0;
	while (ptr[l])
		l++;
	if (l > 1)
		return (1);
	return (-1);
}

void	if_direction(char **direction, t_env **v, char *current)
{
	if (count_arg(direction) == 1)
		ft_printf("cd: too many arguments\n");
	else if (ft_strncmp(direction[0], "-", sizeof(direction[0])) == 0)
	{
		ft_printf("%s\n", env_searsh((*v), "OLDPWD"));
		if (chdir(env_searsh((*v), "OLDPWD")) != -1)
		{
			update_env(v, "PWD", env_searsh((*v), "OLDPWD"));
			update_env(v, "OLDPWD", current);
			g_exit_status = 0;
			return ;
		}
	}
	else if (chdir(direction[0]) != -1)
	{
		update_env(v, "OLDPWD", current);
		getcwd(current, sizeof(current));
		update_env(v, "PWD", current);
		g_exit_status = 0;
		return ;
	}
	perror(direction[0]);
	g_exit_status = 1;
	return ;
}

void	build_cd(char **direction, t_env **v)
{
	char	current[PATH_SIZE];

	getcwd(current, sizeof(current));
	if (direction)
		if_direction(direction, v, current);
	else
	{
		if (chdir(env_searsh((*v), "HOME")) != -1)
		{
			update_env(v, "OLDPWD", current);
			getcwd(current, sizeof(current));
			update_env(v, "PWD", env_searsh((*v), "OLDPWD"));
			g_exit_status = 0;
			return ;
		}
		perror(direction[0]);
		g_exit_status = 1;
	}
	return ;
}
