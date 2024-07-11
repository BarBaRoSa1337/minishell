#include "../minishell.h"

char	*accessible(char *path, char *cmd)
{
	char	*partiel;
	char	*full_path;

	if (ft_strchr(cmd, '/') == NULL)
	{
		partiel = ft_strjoin(ft_strdup("/"), cmd);
		full_path = ft_strjoin(path, partiel);
		if (access(full_path, F_OK | X_OK) != -1)
		{
			free(partiel);
			return (full_path);
		}
		else
		{
			free(partiel);
			free(full_path);
			return (NULL);
		}
	}
	else
	{
		if (access(cmd, F_OK | X_OK) == -1)
			ft_printf("%s: No such file or directory\n", cmd);
		return (cmd);
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
		return (cmd);
	}
	l = 0;
	while (splited_path[l])
	{
		command_path = accessible(ft_strdup(splited_path[l]), cmd);
		if (command_path != NULL)
		{
			ft_free(splited_path);
			return (command_path);
		}
		l++;
	}
	ft_free(splited_path);
	return (NULL);
}
