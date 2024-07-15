/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:36:58 by achakour          #+#    #+#             */
/*   Updated: 2024/07/13 11:52:55 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_9aw9aw3   *locate_struct(void)
{
    t_9aw9aw3   *cmd;

    cmd = malloc(sizeof(t_9aw9aw3));
    if (!cmd)
        return (NULL);
    cmd->cmd_found = 0;
    cmd->index = 0;
    cmd->s = 0;
    cmd->d = 0;
    cmd->tmp = NULL;
    return (cmd);
}

char    *get_str(char *str, int quoeted, t_9aw9aw3 *cmd)
{
    char    *buff;
    char    tmp;
    int     i;
    int     j;

    j = 0;
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
    else
    {
        while (str[j] == ' ')
            ++j;
        while (ft_charchr(str[i], " <|> "))
        {
            printf("aba\n");
            ++i;
        }
        // if ((str[i + j] == 34 || str[i + j] == 39) && ft_strchr((str + i + j), " <|> "))
        // {
        //     tmp = str[i + j];
        //     while (str[i + j] != tmp)
        //         ++i;
        // }
    }
    // while (ft_charchr(str[i], " <|> "))
    //     ++i;
    cmd->index = i;
    printf("index %d\n", i);
    buff = (char *)malloc(sizeof(char) * (i + 1));
    if (!buff)
        return (NULL);
    ft_strlcpy(buff, (str + j), (i + 1));
    return (buff);
}

void    process_cmd(char *str)
{
    char        *buff;
    t_9aw9aw3   *cmd;
    int         i;

    i = 0;
    cmd = locate_struct();
    while (str[cmd->index])
    {
        if (cmd->index > 0 && (str[cmd->index - 1] == 39 || str[cmd->index - 1] == 34) && get_qoutes(str, cmd->index) > 0)
        {
            buff = get_str(str + cmd->index, get_qoutes(str, cmd->index), cmd);
            printf("qouted %s\n", buff);
        }
        if (get_qoutes(str, cmd->index) == 0 && !ft_charchr(str[cmd->index], " <|> "))
        {
            printf("original  %d\n", cmd->index);
            buff = get_str(str + cmd->index, get_qoutes(str, cmd->index), cmd);
            printf("none quoted %s\n", buff);
            // cmd->index += cmd->index;
            //none qouted sequence
        }
        // else if (ft_charchr(str[i], "<|;>"))
        // {
        //     printf("meta char %c\n", str[i]);
        //     // meta charachters
        // }
        ++i;
    }
}

#include <string.h>

int main(int ac, char **ar)
{
    char *str = "hello \"\"world\"\" ''' hello again nega '''  ";
    // char *str = "hello\"aaaaaaaaaaaa\"  ";
    process_cmd(str);
    return (0);
}
