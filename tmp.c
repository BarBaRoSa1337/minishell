/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:37:07 by achakour          #+#    #+#             */
/*   Updated: 2024/07/28 10:11:09 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_shell *tokens_new(void)
{
    t_shell *new;

    new = malloc(sizeof(t_shell));
    if (!new)
        return (NULL);
    new->next = NULL;
    new->args = NULL;
    new->cmd = NULL;
    new->out = 1;
    new->in = 0;
    return (new);
}

t_arg   *arg_new(char *cmd)
{
    t_arg   *new;

    new = malloc(sizeof(t_arg));
    if (!new)
        return (NULL);
    new->arg = ft_strdup(cmd);
    new->next = NULL;
    return (new);
}

void	lst_rje3_lor(t_arg **lst, t_arg *new)
{
	t_arg   *head;

	if (!new || !lst)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	head = *lst;
	while (head->next != NULL)
		head = head->next;
	head->next = new;
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


t_shell *fill_struct(t_a9aw9o3 **cmd)
{
    t_arg       *arg_strct;
    t_shell     *tokens;
    t_a9aw9o3   *iter;
    t_shell     *head;

    tokens = tokens_new();
    arg_strct = NULL;
    head = tokens;
    int         i;

    i = 0;
    iter = *cmd;
    tokens = tokens_new();
    while (iter)
    {
        if (iter->type == 1)
            (tokens)->cmd = ft_strdup(iter->cmd);
        else if (iter->type == 2)
            lst_rje3_lor(&arg_strct, arg_new(ft_strdup(iter->cmd)));
        // else if (iter->type == 3 && !ft_strchr(iter->cmd, ">"))
        // {
        //     if ((tokens + i)->out != 1)
        //         close ((tokens + i)->out);
        //     (tokens + i)->out = open(iter->cmd, O_RDWR|O_CREAT, 777);
        // }
        // else if (iter->type == 5 && !ft_strchr(iter->cmd, ">>"))
        // {
        //    if ((tokens + i)->out != 1)
        //      close((tokens + i)->out);
        //     (tokens + i)->out = open(iter->cmd, O_RDWR|O_CREAT|O_APPEND, 777);
        // }
        // else if (iter->type == 4 && !ft_strchr(iter->cmd, "<"))
        // {
        //    if ((tokens + i)->in != 1)
        //      close((tokens + i)->in);
        //     (tokens + i)->in = open(iter->cmd, O_RDWR, 777);
        //     if ((tokens + i)->in == -1)
        //         printf("infile:%s not found\n", iter->cmd);
        // }
        // else if (iter->type == 6 && !ft_strchr(iter->cmd), "<<")
        //     her_dog(iter->next->cmd);
        // else if (iter->type == 7)
        // {
        //     tokens->next = tokens_new();
        //     ++i;
        // }
        (tokens + i)->args = arg_strct;
        iter = iter->next;
    }
    return (head);
}
