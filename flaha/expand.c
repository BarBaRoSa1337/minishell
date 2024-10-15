/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:32:44 by achakour          #+#    #+#             */
/*   Updated: 2024/09/12 16:44:34 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*expander_cont(char *str, int x, int *y, t_env *env)
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

char	**exp_split(char *str)
{
	char	**buff;

	if (!str)
		return (NULL);
	if (ft_charchr(' ', str))
		buff = ft_split(str, ' ');
	else if (ft_charchr('\t', str))
		buff = ft_split(str, '\t');
	if (!buff || !buff[0])
		return (NULL);
	return (buff);
}

void	ambigigius_red(t_a9aw9o3 *tokens, int i)
{
	if ((tokens->type >= 3 && tokens->type <= 5) && !get_qoutes(tokens->cmd, i))
	{
		g_exit_status = 1;
		printf("%s ambigious redirection\n", tokens->cmd + i);
		tokens->err = 1;
	}
}

void	exp_copy(t_a9aw9o3 *tokens, char *result, int i, int j)
{
	char	*buff;
	char	*tmp;

	if (!tokens->cmd)
		return ;
	tmp = tokens->cmd;
	if (space_exp(result))
		handle_space_exp(tokens, tokens->next, result);
	else
	{
		buff = ft_strjoin_ex(ft_get_str(tokens->cmd, i - 1), result);
		if (tokens->cmd[i + j])
			buff = ft_strjoin_ex(buff, tokens->cmd + i + j);
		tokens->cmd = buff;
	}
	if (!tokens->cmd || !tokens->cmd[0])
		sanitize_tokens(tokens->next);
	(free(result), free(tmp));
	return ;
}

void	expander(t_a9aw9o3 *tokens, t_env *env)
{
	char	*result;
	int		i;
	int		j;

	while (tokens)
	{
		i = 0;
		while (tokens->cmd[i])
		{
			j = 0;
			if (tokens->cmd[i] == '$' && tokens->cmd[i + 1]
				&& is_alphanum(tokens->cmd[i + 1]) && tokens->type != 6
				&& get_qoutes(tokens->cmd, i + 1) != 1)
			{
				i++;
				result = expander_cont(tokens->cmd, i, &j, env);
				ambigigius_red(tokens, i);
				exp_copy(tokens, result, i, j);
				i = 0;
			}
			else
				++i;
		}
		tokens = tokens->next;
	}
}
