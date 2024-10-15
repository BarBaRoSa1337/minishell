/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9aw9a3a_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 11:38:15 by achakour          #+#    #+#             */
/*   Updated: 2024/09/12 23:38:10 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_quotes(char *str)
{
	int	s_quotes;
	int	d_quotes;
	int	i;

	i = 0;
	s_quotes = 0;
	d_quotes = 0;
	while (str[i])
	{
		if (str[i] == 39)
			s_quotes++;
		else if (str[i] == 34)
			d_quotes++;
		++i;
	}
	if (s_quotes % 2 == 0 && d_quotes % 2 == 0)
		return (1);
	return (0);
}

int	her_check(char *str)
{
	int	her;
	int	i;

	i = 0;
	her = 0;
	while (str[i])
	{
		if (str[i] == '<' && str[i + 1] == '<')
		{
			++her;
			i += 2;
		}
		else
			++i;
	}
	if (her >= 16)
	{
		printf("minishell: maximum here-document count exceeded\n");
		free(str);
		exit(2);
	}
	return (0);
}

int	check_syntax2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '<' || str[i] == '>')
		{
			if (str[i] == str[i + 1])
				++i;
			++i;
			while (str[i] == ' ')
				++i;
			if (str[i] == '<' || str[i] == '>')
			{
				g_exit_status = 2;
				printf("minishell: Syntax Error near unexpected token '%c'\n",
					str[i]);
				return (free(str), 0);
			}
		}
		++i;
	}
	if (her_check(str) == 1)
		return (0);
	return (1);
}

int	check_syntax(char *str)
{
	int	len;

	if (!str || !str[0])
		return (0);
	len = ft_strlen(str);
	while (str[len - 1] == ' ')
		--len;
	if (str[len - 1] == '|' || str[0] == '|' || str[len - 1] == '<' || str[len
			- 1] == '>')
	{
		g_exit_status = 2;
		printf("minishell: syntax error near unexpected token\n");
		return (free(str), 0);
	}
	if (get_qoutes(str, ft_strlen(str)) != 0)
	{
		printf("minishell: Syntax Error in quotes\n");
		return (free(str), 0);
	}
	return (check_syntax2(str));
}
