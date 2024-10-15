/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:47:13 by csaidi            #+#    #+#             */
/*   Updated: 2024/09/04 17:47:14 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handler(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	g_exit_status = 130;
}

void	sig(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
	}
	g_exit_status = 130;
}

void	sig_quit(int signal)
{
	(void)signal;
	printf("Quit (core dumped)\n");
	g_exit_status = 131;
}
