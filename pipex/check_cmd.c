#include "../minishell.h"

char	**command_tableau(char *cmd)
{
	char	**cmd_plus_arg;

	if (ft_strchr(cmd, '\t') != NULL)
	{
		cmd_plus_arg = ft_split(cmd, '\t');
		return (cmd_plus_arg);
	}
	cmd_plus_arg = ft_split(cmd, ' ');
	return (cmd_plus_arg);
}

void	check_cmd(char *cmd, char *env, t_var *t)
{
	if (env)
	{
		t->cmd_1 = command_tableau(cmd);

		if (t->cmd_1[0] != NULL)
			t->cmd_path_1 = if_accessible(t->cmd_1[0], env);

		if (!(t->cmd_path_1) || t->cmd_1[0] == NULL)
			ft_printf("%s: command not found\n", t->cmd_1[0]);
	}
}
