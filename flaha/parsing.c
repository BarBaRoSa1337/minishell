/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:36:58 by achakour          #+#    #+#             */
/*   Updated: 2024/09/12 11:24:25 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	get_meta_chars(char *str, int *index, t_a9aw9o3 **shell)
{
	char	*buff;
	int		i;

	i = 0;
	while (ft_charchr(str[i], "<|>"))
		++i;
	*index += i;
	buff = (char *)malloc(sizeof(char) * (i + 1));
	if (!buff)
		return ;
	ft_strlcpy(buff, str, (i + 1));
	add_back_9aw9a3a(shell, lstnew_9aw9a3a(buff, 0));
}

void	get_none_quoted(char *str, int *index, t_a9aw9o3 **shell)
{
	char	*buff;
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_charchr(str[i], " <|> ") && get_qoutes(str, i) == 0)
			break ;
		++i;
	}
	*index += i;
	buff = (char *)malloc(sizeof(char) * (i + 1));
	if (!buff)
		return ;
	ft_strlcpy(buff, str, (i + 1));
	add_back_9aw9a3a(shell, lstnew_9aw9a3a(buff, 0));
}

void	get_single_qoted(char *str, int *index, t_a9aw9o3 **shell)
{
	char	*buff;
	int		i;

	i = 0;
	while (str[i] != 39)
		++i;
	while (str[i])
	{
		if (ft_charchr(str[i], " <|> ") && !get_qoutes(str, i))
			break ;
		++i;
	}
	*index += i;
	buff = (char *)malloc(sizeof(char) * (i + 1));
	if (!buff)
		return ;
	ft_strlcpy(buff, str, (i + 1));
	add_back_9aw9a3a(shell, lstnew_9aw9a3a(buff, 1));
}

void	get_double_quoted(char *str, int *index, t_a9aw9o3 **shell)
{
	char	*buff;
	int		i;

	i = 0;
	while (str[i] != 34)
		++i;
	while (str[i])
	{
		if (ft_charchr(str[i], " <|> ") && !get_qoutes(str, i))
			break ;
		++i;
	}
	*index += i;
	buff = (char *)malloc(sizeof(char) * (i + 1));
	if (!buff)
		return ;
	ft_strlcpy(buff, str, (i + 1));
	add_back_9aw9a3a(shell, lstnew_9aw9a3a(buff, 2));
}

t_shell	*parsing(char *str, t_env *env)
{
	t_a9aw9o3	*tokens;
	int			i;

	i = 0;
	tokens = NULL;
	if (!check_syntax(str))
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\"')
			get_double_quoted(str + i, &i, &tokens);
		else if (str[i] == '\'')
			get_single_qoted(str + i, &i, &tokens);
		else if (!get_qoutes(str, i) && !ft_charchr(str[i], " <|>\"\'"))
			get_none_quoted(str + i, &i, &tokens);
		else if (ft_charchr(str[i], "<|>") && !get_qoutes(str, i))
			get_meta_chars(str + i, &i, &tokens);
		else if (str[i] == ' ' || str[i] == '\t')
			++i;
	}
	process_red(tokens);
	sanitize_tokens(tokens);
	expander(tokens, env);
	remove_quotes(tokens);
	return (free(str), fill_struct(&tokens, env));
}
