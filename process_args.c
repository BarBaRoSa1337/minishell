/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:38:41 by achakour          #+#    #+#             */
/*   Updated: 2024/07/21 11:45:37 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    sanitize_tokens(t_a9aw9o3 *cmd)
{
    int         before;
    int         cmd_found;
    t_a9aw9o3   *head;
    
    before = 0; 
    head = cmd;
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

void    remove_quotes(t_a9aw9o3 **tokens)
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

void    fill_struct(t_a9aw9o3 **cmd)
{
    t_a9aw9o3   *iter;
    t_shell     *tokens;
    t_arg       *arg_strct;
    int i;

    i = 0;
    tokens = tokens_new();
    iter = *cmd;
    while (iter)
    {
        if (iter->type == 1)
            (tokens + i)->cmd = ft_strdup(iter->cmd);
        else if (iter->type == 2)
            // ft_lstadd_back(&arg_strct);// creat this
        else if (iter->type == 3)
            (tokens + i)->out = open(iter->next->cmd, O_RDWR|O_CREAT, 0666);
        else if (iter->type == 5)
            (tokens + i)->out = open(iter->next->cmd, O_RDWR|O_CREAT|O_APPEND, 0666);
        else if (iter->type == 4)
        {
            (tokens + i)->out = open(iter->next->cmd, O_RDWR, 0666);
            if ((tokens + i)->out == -1)
                printf("infile:%s not found\n", iter->next->cmd);
        }
        else if (iter->type == 6)
            her_dog(iter->next->cmd);
        else if (iter->type == 7)
        {
            tokens = tokens_new();// and this
            i ++;
        }
        if (iter->next)
            iter = iter->next;
    }
    tokens->args = arg_strct;
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
