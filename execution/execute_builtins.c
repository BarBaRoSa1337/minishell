/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:45:52 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/12 16:47:13 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	counter(char **ptr)
{
	int	l;
	int	i;

	if (!ptr || !ptr[0])
		return (-1);
	i = 0;
	l = 1;
	while (ptr[l])
	{
		l++;
		i++;
	}
	return (i);
}

char	**rm_cmd(char **p)
{
	char	**args;
	int		len;
	int		i;

	if (!p)
		return (NULL);
	len = counter(p);
	if (len != -1)
	{
		args = malloc((len + 1) * sizeof(char *));
		args[len] = NULL;
		len = 1;
		i = 0;
		while (p[len])
		{
			args[i] = ft_strdup(p[len]);
			len++;
			i++;
		}
		return (args);
	}
	return (NULL);
}

int	is_builtins(t_ms *e)
{
	if (!e->cmd)
		return (-1);
	if (ft_strncmp(e->cmd, "cd", sizeof(e->cmd)) == 0)
		return (1);
	else if (ft_strncmp(e->cmd, "echo", sizeof(e->cmd)) == 0)
		return (1);
	else if (ft_strncmp(e->cmd, "unset", sizeof(e->cmd)) == 0)
		return (1);
	else if (ft_strncmp(e->cmd, "pwd", sizeof(e->cmd)) == 0)
		return (1);
	else if (ft_strncmp(e->cmd, "export", sizeof(e->cmd)) == 0)
		return (1);
	else if (ft_strncmp(e->cmd, "env", sizeof(e->cmd)) == 0)
		return (1);
	else if (ft_strncmp(e->cmd, "exit", sizeof(e->cmd)) == 0)
		return (1);
	else
		return (-1);
}

int	execute_builtins(t_ms *e, t_env **v)
{
	char	**arg;

	arg = rm_cmd(e->arg);
	if (ft_strncmp(e->cmd, "cd", sizeof(e->cmd)) == 0)
		build_cd(arg, v);
	else if (ft_strncmp(e->cmd, "echo", sizeof(e->cmd)) == 0)
		build_echo(arg, 1);
	else if (ft_strncmp(e->cmd, "unset", sizeof(e->cmd)) == 0)
		build_unset(arg, v, 0);
	else if (ft_strncmp(e->cmd, "pwd", sizeof(e->cmd)) == 0)
		build_pwd(arg);
	else if (ft_strncmp(e->cmd, "export", sizeof(e->cmd)) == 0)
		build_export(arg, v);
	else if (ft_strncmp(e->cmd, "env", sizeof(e->cmd)) == 0)
		build_env((*v), arg);
	else if (ft_strncmp(e->cmd, "exit", sizeof(e->cmd)) == 0)
		build_exit(arg);
	else
		return (ft_free(arg), -1);
	return (ft_free(arg), 0);
}
