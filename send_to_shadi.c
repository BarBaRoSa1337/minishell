/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_to_shadi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 10:44:45 by achakour          #+#    #+#             */
/*   Updated: 2024/07/23 18:37:31 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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

void	lst_rje3_lor(t_arg **lst, char *cmd)
{
	t_arg   *head;
    t_arg   *new;

    new = malloc(sizeof(t_arg));
	if (!new || lst == NULL)
		return ;
    new->arg = ft_strdup(cmd);
    new->next = NULL;
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

t_shell *fill_struct(t_a9aw9o3 **cmd)
{
    t_arg       *arg_strct;
    t_shell     *tokens;
    t_a9aw9o3   *iter;
    int         i;

    i = 0;
    iter = *cmd;
    tokens = tokens_new();
    while (iter)
    {
        if (iter->type == 1)
            (tokens + i)->cmd = ft_strdup(iter->cmd);
        else if (iter->type == 2)
        {
            lst_rje3_lor(&arg_strct, iter->cmd);
        }
        else if (iter->type == 3 && !ft_strchr(iter->cmd, ">"))
        {
            if ((tokens + i)->out != 1)
                close ((tokens + i)->out);
            (tokens + i)->out = open(iter->cmd, O_RDWR|O_CREAT, 777);
        }
        // else if (iter->type == 5 && !ft_strchr(iter->cmd, ">>"))
        // {
        //     close((tokens + i)->out);
        //     (tokens + i)->out = open(iter->cmd, O_RDWR|O_CREAT|O_APPEND, 777);
        // }
        // else if (iter->type == 4 && !ft_strchr(iter->cmd, "<"))
        // {
        //     close((tokens + i)->in);
        //     (tokens + i)->out = open(iter->cmd, O_RDWR, 777);
        //     if ((tokens + i)->out == -1)
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
    return (tokens);
}

int is_alpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    return (0);
}

char    *expander(t_a9aw9o3 *tokens, t_arg *env)//need a get_env function to get the env value and the linked list of env values
{
    char    *buff;
    int     i;
    int     j;

    while (tokens)
    {
        i = 0;
        while (tokens->cmd[i])
        {
            if (tokens->cmd[i] == '$')
            {
                while (!is_alpha(tokens->cmd[i]))
                    ++i;
                while (is_alpha(tokens->cmd[i + j]))
                    ++j;
                buff = (char *)malloc(size_t(char));
                while (is_alpha(tokens->cmd[i + j]))
                    buff[i + j] = tokens->cmd[i + j];
                char *exp = get_env(buff);
            }
        }
        tokens = tokens->next;
    }
}
