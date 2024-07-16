/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:36:58 by achakour          #+#    #+#             */
/*   Updated: 2024/07/16 18:47:53 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *get_str(char *str, int quoeted, int *index,t_9aw9aw3 *cmd)
{
    char    *buff;
    int     i;

    i = 0;
    if (quoeted == 1)
    {
        while (str[i] != 39)
            ++i;
    }
    else if (quoeted == 2)
    {
        while (str[i] != 34)
            ++i;
    }
    while (str[i])
    {
        if (ft_charchr(str[i], " <|> ") == 1 && get_qoutes(str, i) == 0)
            break;
        ++i;
    }
    *index = i;
    buff = (char *)malloc(sizeof(char) * (i + 1));
    if (!buff)
        return (NULL);
    ft_strlcpy(buff, str, (i + 1));
    return (buff);
}

void    process_cmd(char *str)
{
    char        *buff;
    t_9aw9aw3   *cmd;
    int         i;

    i = 0;
    cmd = locate_struct();
    int len = ft_strlen(str);
    while (i < len)
    {
        if ((str[i] == '\"' || str[i] == '\''))
        {
            buff = get_str(str, get_qoutes(str, i + 1), &i, cmd);
            printf("quoted %s\n", buff);
            free(buff);
        }
        else if (get_qoutes(str, i) == 0 && ft_charchr(str[i], " <|>\"\'") == 0)
        {
            
        }
        else if (str[i] == ' ' || str[i] == '\"' || str[i] == '\'')
            ++i;
    }
}

#include <string.h>

int main(int ac, char **ar)
{
    // char *str = "\"hello\"  ''' hello again nega '''  ";
    // char *str = ' "world" ';
    // char *input = readline("minishell $");
    process_cmd(ar[1]);
    return (0);
}
