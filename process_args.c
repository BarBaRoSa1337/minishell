/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:38:41 by achakour          #+#    #+#             */
/*   Updated: 2024/07/16 18:22:05 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void    process_cmd(t_a9aw9o3 *cmd)
// {
//     t_a9aw9o3   *head;
//     t_9aw9aw3   info;
//     int before;

//     before = 0;
//     head = cmd;
//     info.cmd_found = 0;
//     while (head)
//     {
//         if (head->type > 2 && head->type < 9)
//         {
//             before = head->type;
//         }
//         else if (before != 0)
//         {
//             head->type = before;
//             before = 0;
//         }
//         else if (info.cmd_found == 0)
//         {
//             info.cmd_found = 1;
//             head->type = 1;
//         }
//         else if (info.cmd_found == 1)
//             head->type = 2;
//         head = head->next;
//     }
// }

// void    process_red(t_a9aw9o3 *cmd)
// {
//     t_a9aw9o3   *head;

//     head = cmd;
//     while (head)
//     {
//         if (head->quoted = 0 && ft_strchr(head->cmd, ">"))
//             head->type = 3;
//         else if (head->quoted = 0 && ft_strchr(head->cmd, ">>"))
//             head->type = 5;
//         else if (head->quoted = 0 && ft_strchr(head->cmd, "<"))
//             head->type = 4;
//         else if (head->quoted = 0 && ft_strchr(head->cmd, "<<"))
//             head->type = 6;
//         else if (head->quoted = 0 && ft_strchr(head->cmd, "|"))
//             head->type = 7;
//         else if (head->quoted = 0 && ft_strchr(head->cmd, ";"))
//             head->type = 8;
//         head = head->next;
//     }
// }

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