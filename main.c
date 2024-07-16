/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:36:58 by achakour          #+#    #+#             */
/*   Updated: 2024/07/16 13:34:45 by achakour         ###   ########.fr       */
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
    // else
    // {
    //     while (str[j] == ' ')
    //         ++j;
    //     while (ft_charchr(str[i + j], " <|> ") == 0 && )
    //         ++i;
    // }
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
    while (str[i])
    {
        if (get_qoutes(str, i) > 0 || ft_charchr(str[i], "\"\'"))
        {
            printf("before %d\n", i);
            buff = get_str(str + i, get_qoutes(str, i), &i, cmd);
            printf("after %d\n", i);
            printf("quoted %s\n", buff);
            free(buff);
        }
        // else if (get_qoutes(str, i) == 0 && ft_charchr(str[i], " <|>\"\'") == 0)
        // {
        //     buff = get_str(str + i, get_qoutes(str, i), &i, cmd);
        //     printf("none quoted +%s+\n", buff);
        //     free (buff);
        // }
        else if (str[i] == ' ')
            ++i;
    }
}

void    process_red(t_a9aw9o3 *cmd)
{
    t_a9aw9o3   *head;

    head = cmd;
    while (head)
    {
        if (head->quoted = 0 && ft_strchr(head->cmd, ">"))
            head->type = 3;
        else if (head->quoted = 0 && ft_strchr(head->cmd, ">>"))
            head->type = 5;
        else if (head->quoted = 0 && ft_strchr(head->cmd, "<"))
            head->type = 4;
        else if (head->quoted = 0 && ft_strchr(head->cmd, "<<"))
            head->type = 6;
        else if (head->quoted = 0 && ft_strchr(head->cmd, "|"))
            head->type = 7;
        else if (head->quoted = 0 && ft_strchr(head->cmd, ";"))
            head->type = 8;
        head = head->next;
    }
}

void    process_cmd(t_a9aw9o3 *cmd)
{
    t_a9aw9o3   *head;
    t_9aw9aw3   info;
    int before;

    before = 0;
    head = cmd;
    info.cmd_found = 0;
    while (head)
    {
        if (head->type > 2 && head->type < 9)
        {
            before = head->type;
        }
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
        else if (info.cmd_found == 1)
            head->type = 2;
        head = head->next;
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
