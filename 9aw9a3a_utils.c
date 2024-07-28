/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9aw9a3a_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 11:38:15 by achakour          #+#    #+#             */
/*   Updated: 2024/07/28 10:11:09 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int check_quotes(char *str)
{
    int s_quotes;
    int d_quotes;
    int i;

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

int check_syntax(char *str)
{
    int len;
    int i;

    i = 0;
    len = strlen(str);
    while (str[len - 1] == ' ')
        --len;
    if (str[len - 1] == '|' || str[i] == '|' || str[len - 1] == '<' || str[len - 1] == '>')
        perror("minishell: Syntax Error\n");
    while (str[i])
    {
        if ((str[i] == '<' || str[i] == '>'))
        {
            ++i;
            if (str[i] != ' ')
                ++i;
            while (str[i] == ' ')
                ++i;
            if (str[i] == '<' || str[i] == '>' || str[i] == '|')
                perror("minishell: Syntax Error\n");
        }
        ++i;
    }
    return (1);
}

int get_qoutes(char *str, int index)
{
    int i;
    int quotes;

    i = 0;
    quotes = 0;
    while (i < index && str[i])
    {
        if (str[i] == 39 && quotes < 1)
            quotes = 1;
        else if (str[i] == 34 && quotes < 1)
            quotes = 2;
        else if (str[i] == 39 && quotes == 1)
            quotes = 0;
        else if (str[i] == 34 && quotes == 2)
            quotes = 0;
        ++i;
    }
    return (quotes);
}

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstlen >= dstsize)
	{
		return (srclen + dstsize);
	}
	if (0 < dstsize - dstlen - 1)
	{
		ft_strlcpy(dst + dstlen, src, dstsize - dstlen);
	}
	return (dstlen + srclen);
}