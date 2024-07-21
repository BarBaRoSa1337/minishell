/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:38:41 by achakour          #+#    #+#             */
/*   Updated: 2024/07/21 11:21:48 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    sanitize_tokens(t_a9aw9o3 *cmd)
{
    int         before;
    t_a9aw9o3   *head;
    t_9aw9aw3   info;

    head = cmd;
    before = 0; 
    info.cmd_found = 0;
    while (head)
    {
        if (head->type > 2 && head->type < 7)
            before = head->type;
        else if (before != 0)
        {
            head->type = before;
            before = 0;
        }
        else if (info.cmd_found == 0)
        {
            info.cmd_found = 1;
            head->type = 1;
        }
        else if (info.cmd_found == 1 && head->type == 0)
            head->type = 2;
        else if (head->type == 7)
            info.cmd_found = 0;
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

char    *remove_quotes(t_a9aw9o3 **tokens)
{
    t_a9aw9o3   *iter;
    char        *buff;
    int         i;
    int         j;

    iter = *tokens;
    while (iter)
    {
        buff = iter->cmd;
        i = 0;
        while (buff[i])
            if (get_qoutes(buff, i) > 0)
                ++i;
        j = 0;
        buff = (char *)malloc((sizeof(char) * i + 1));
        i = 0;
        while (iter->cmd[i])
        {
            if (get_qoutes(iter->cmd, i) > 0)
                buff[j++] = iter->cmd[i];
            else
                ++i;
        }
        iter = iter->next;
    }
}

// char    *expander(char *str)
// {
//     char    *buff;
//     char    *exp;
//     int     i;
//     int     j;

//     i = 0;
//     while (str[i])
//     {
//         if (str[i] == '$' && get_qoutes(str, i) != 1)
//         {
//             exp = getenv(get_name(str[i], &j));
//             buff = ft_strjoin(str , exp, &i);
//             ft_strjoin(buff, str + j, &i);
//             break ;
//         }
//         ++i;
//     }
//     return (buff);
// }
