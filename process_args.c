/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:38:41 by achakour          #+#    #+#             */
/*   Updated: 2024/07/28 10:16:40 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void    sanitize_tokens(t_a9aw9o3 *cmd)
{
    int         cmd_found;
    int         before;
    t_a9aw9o3   *head;
    
    head = cmd;
    before = 0;
    cmd_found = 0;
    while (head)
    {
        if (head->type > 2 && head->type < 7)
            before = head->type;
        else if (before != 0)
        {
            head->type = before;
            before = 0;
        }
        else if (cmd_found == 0)
        {
            cmd_found = 1;
            head->type = 1;
        }
        else if (cmd_found == 1 && head->type == 0)
            head->type = 2;
        else if (head->type == 7)
            cmd_found = 0;
        head = head->next;
    }
}

void    process_red(t_a9aw9o3 *cmd)
{
    t_a9aw9o3   *head;
    char        *str;

    head = cmd;
    while (head)
    {
        str = head->cmd;
        if (head->quoted == 0 && str[0] == '>' && str[1] == '>')
            head->type = 5;
        else if (head->quoted == 0 && ft_strchr(head->cmd, ">"))
            head->type = 3;
        else if (head->quoted == 0 && str[0] == '<' && str[1] == '<')
            head->type = 6;
        else if (head->quoted == 0 && ft_strchr(head->cmd, "<"))
            head->type = 4;
        else if (head->quoted == 0 && ft_strchr(head->cmd, "|"))
            head->type = 7;
        else
            head->type = 0;
        head = head->next;
    }
}

char    *ft_replace(char *cmd, int len)
{
    int     i;
    int     j;
    char    *buff;
    char    *tmp;
    int     flag;

    i = 0;
    j = 0;
    flag = 0;
    tmp = cmd;
    buff = malloc(sizeof(char) * len + 1);
    if (!buff)
        return (NULL);
    while (cmd[i])
    {
        if (cmd[i] == '\'' && flag == 0)
        {
            ++i;
            flag = 1;
        }
        else if (cmd[i] == '\"' && flag == 0)
        {
            flag = 2;
            ++i;
        }
        else if ((cmd[i] == '\'' && flag == 1) || (cmd[i] == '\"' && flag == 2))
        {
            ++i;
            flag = 0;
        }
        else if (cmd[i] == '\"' && flag == 2)
        {
            flag = 0;
            ++i;
        }
        else
            buff[j++] = cmd[i++];
    }
    buff[j] = '\0';
    return (free(tmp), buff);
}

void    remove_quotes(t_a9aw9o3 *bash)
{
    int         flag;
    int         i , j;

    flag = 0;
    while (bash)
    {
        i = j = 0;
        while (bash->cmd[i + j])
        {
            if (bash->cmd[i + j] == '\'' && flag == 0)
            {
                ++j;
                flag = 1;
            }
            else if (bash->cmd[i + j] == '\"' && flag == 0)
            {
                flag = 2;
                ++j;
            }
            else if (bash->cmd[i + j] == '\'' && flag == 1)
            {
                ++j;
                flag = 0;
            }
            else if (bash->cmd[i + j] == '\"' && flag == 2)
            {
                flag = 0;
                ++j;
            }
            else
                ++i;
        }
        bash->cmd = ft_replace(bash->cmd, i);
        bash = bash->next;
    }
}
