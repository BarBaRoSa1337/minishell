/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 18:02:12 by achakour          #+#    #+#             */
/*   Updated: 2024/09/09 10:27:01 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	sig_her(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
		g_exit_status = 130;
		exit(130);
	}
	return ;
}

char	*expander_cont1(char *str, int x, int *y, t_env *env)
{
	char	*result;
	char	*buff;
	int		i;
	int		j;

	i = x;
	j = -1;
	if (str[x] == '?')
	{
		*y = 1;
		return (ft_itoa(g_exit_status));
	}
	while (is_alphanum(str[i + ++j]))
		;
	buff = (char *)malloc(sizeof(char) * (j + 1));
	if (!buff)
		return (NULL);
	j = -1;
	while (is_alphanum(str[i + ++j]))
		buff[j] = str[i + j];
	buff[j] = '\0';
	*y = j;
	result = get_env(buff, env);
	return (free(buff), result);
}

char	*her_expander(char *str, t_env *env)
{
	char	*result;
	char	*buff;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i] == '$' && is_alphanum(str[i + 1]))
		{
			i++;
			result = expander_cont1(str, i, &j, env);
			buff = ft_strjoin_ex(ft_get_str(str, i - 1), result);
			if (str[i + j])
				buff = ft_strjoin_ex(buff, str + i + j);
			(free(result), free(str));
			str = buff;
			i = 0;
		}
		else
			++i;
	}
	return (buff);
}

int	her_cont(char *del, int fd, t_env *env, int quotes)
{
	char	*buff;

	buff = readline(">");
	if (!buff)
	{
		printf("minishell: warning: here-document ");
		printf("delimited by end-of-file (wanted `her')\n");
		return (free(buff), 0);
	}
	if (ft_strncmp(buff, del, sizeof(buff)) == 0)
	{
		return (free(buff), 0);
	}
	if (quotes == 0 && is_exp(buff))
	{
		buff = her_expander(buff, env);
	}
	ft_putstr_fd(buff, fd);
	ft_putchar_fd('\n', fd);
	return (free(buff), 1);
}

int	ft_heredoc(char *del, t_env *env, int qoutes)
{
	int	fd[2];
	int	pid;

	pipe(fd);
	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		while (1)
		{
			signal(SIGINT, sig_her);
			if (!her_cont(del, fd[1], env, qoutes))
				break ;
		}
		exit(0);
	}
	waitpid(pid, NULL, 0);
	return (close(fd[1]), fd[0]);
}
