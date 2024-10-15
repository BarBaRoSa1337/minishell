/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:49:51 by achakour          #+#    #+#             */
/*   Updated: 2024/09/11 10:31:22 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_status = 0;

void	ft_minishell(char *input, t_env **env)
{
	t_shell	*shell;
	char	**envp;
	t_ms	*ms;

	shell = parsing(input, *env);
	ms = forming_list(shell, 0);
	envp = env_to_ptr(*env);
	execute_cmd(&ms, env, envp, 0);
	ft_free(envp);
	free_ms(&ms);
}

int	main(int ac, char **ar, char **envp)
{
	char	*input;
	t_env	*env;

	(void)ac;
	(void)ar;
	env = NULL;
	get_envp(envp, &env);
	while (1)
	{
		signal(SIGINT, handler);
		signal(SIGQUIT, SIG_IGN);
		input = readline("minishell $:");
		signal(SIGQUIT, sig_quit);
		signal(SIGINT, sig);
		if (!input)
		{
			free_env(&env);
			exit(0);
		}
		add_history(input);
		ft_minishell(input, &env);
	}
	return (0);
}
