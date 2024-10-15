/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:45:24 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/12 18:27:49 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*accessible(char *path, char *cmd)
{
	char	*partiel;
	char	*full_path;

	if (!cmd[0])
		return (NULL);
	if (ft_strchr(cmd, '/') == NULL)
	{
		partiel = ft_strjoin("/", cmd);
		full_path = ft_strjoin(path, partiel);
		if (access(full_path, F_OK | X_OK) != -1)
			return (free(partiel), full_path);
		else
			return (free(partiel), free(full_path), NULL);
	}
	else
	{
		if (open(cmd, __O_DIRECTORY) > 0)
			ft_printf("%s: Is a directory\n", cmd);
		else if (access(cmd, F_OK | X_OK) == -1)
			ft_printf("%s: No such file or directory\n", cmd);
		return (g_exit_status = 1, ft_strdup(cmd));
	}
}

char	*if_accessible(char *cmd, char *env)
{
	char	**splited_path;
	char	*command_path;
	int		l;

	splited_path = ft_split(env, ':');
	if (!splited_path)
	{
		if (access(cmd, F_OK | X_OK) == -1)
			ft_printf("%s: No such file or directory\n", cmd);
		return (g_exit_status = 1, cmd);
	}
	l = 0;
	while (splited_path[l])
	{
		command_path = accessible(splited_path[l], cmd);
		if (command_path != NULL)
			return (ft_free(splited_path), free(cmd), command_path);
		free(command_path);
		l++;
	}
	ft_free(splited_path);
	ft_printf("%s: command not found\n", cmd);
	return (g_exit_status = 127, free(cmd), NULL);
}

void	check_cmd(t_ms **e, t_env *v)
{
	char	*path;
	t_ms	*head;

	head = (*e);
	path = ft_strdup(env_searsh(v, "PATH"));
	while (head)
	{
		if (head->cmd != NULL && is_builtins(head) == -1)
			head->cmd = if_accessible(head->cmd, path);
		head = head->next;
	}
	if (path)
		free(path);
}
