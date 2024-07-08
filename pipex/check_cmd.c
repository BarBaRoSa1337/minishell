#include "../minishell.h"

void	check_cmd(char **av, char **env, t_var *t)
{
	t->cmd_1 = command_tableau(av[2]);
	t->cmd_2 = command_tableau(av[3]);

	if (t->cmd_1[0] != NULL)
		t->cmd_path_1 = if_accessible(t->cmd_1[0], env);
	if (t->cmd_2[0] != NULL)
		t->cmd_path_2 = if_accessible(t->cmd_2[0], env);

	if (!(t->cmd_path_1) || t->cmd_1[0] == NULL)
		ft_printf("%s: command not found\n", t->cmd_1[0]);
	if (!(t->cmd_path_2) || t->cmd_2[0] == NULL)
		ft_printf("%s: command not found\n", t->cmd_2[0]);
}
