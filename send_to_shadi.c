/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_to_shadi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 10:44:45 by achakour          #+#    #+#             */
/*   Updated: 2024/07/22 10:45:09 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void    fill_struct(t_a9aw9o3 **cmd)
// {
//     t_a9aw9o3   *iter;
//     t_shell     *tokens;
//     t_arg       *arg_strct;
//     int i;

//     i = 0;
//     tokens = tokens_new();
//     iter = *cmd;
//     while (iter)
//     {
//         if (iter->type == 1)
//             (tokens + i)->cmd = ft_strdup(iter->cmd);
//         else if (iter->type == 2)
//             // ft_lstadd_back(&arg_strct);// creat this
//         else if (iter->type == 3)
//             (tokens + i)->out = open(iter->next->cmd, O_RDWR|O_CREAT, 0666);
//         else if (iter->type == 5)
//             (tokens + i)->out = open(iter->next->cmd, O_RDWR|O_CREAT|O_APPEND, 0666);
//         else if (iter->type == 4)
//         {
//             (tokens + i)->out = open(iter->next->cmd, O_RDWR, 0666);
//             if ((tokens + i)->out == -1)
//                 printf("infile:%s not found\n", iter->next->cmd);
//         }
//         else if (iter->type == 6)
//             her_dog(iter->next->cmd);
//         else if (iter->type == 7)
//         {
//             tokens = tokens_new();// and this
//             i ++;
//         }
//         if (iter->next)
//             iter = iter->next;
//     }
//     tokens->args = arg_strct;
// }

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
