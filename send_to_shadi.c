/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_to_shadi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 10:44:45 by achakour          #+#    #+#             */
/*   Updated: 2024/07/28 10:16:53 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include " parsing.h"

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

int is_alpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    return (0);
}

// void    open_files(char file, int type, t_shell *tokens)
// {
//     t_shell *p;

//     p = tokens;
//     while (p->next)//iterate the the final node because each pipe a new node created so iterate to the last one
//         p = p->next;
//     if (type == 3)
//         open(file, O_RDWR|O_CREAT, 644);
//     //else if (type == 4)
// }

// void    her_dog(char *del)
// {
//     char    *buff;
//     char    *tmp;
//     int     fd;

//     fd = open;  
//     buff = NULL;
//     while (ft_strchr(buff, del))
//     {
//         tmp = get_next_line(0);
//         buff = ft_strjoin(buff, tmp);
//     }
//     write(fd, buff, ft_strlen(buff));
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
    iter = *cmd;
    while (iter)
    {
        if (iter->type == 1)
            (tokens)->cmd = ft_strdup(iter->cmd);
        else if (iter->type == 2)
            lst_rje3_lor(&arg_strct, arg_new(ft_strdup(iter->cmd)));
        else if (iter->type == 3 && !ft_strchr(iter->cmd, ">"))
        {
            // open_file(iter->cmd, iter->type, );
            printf("fd before %d\n", tokens->out);
            if (tokens->out > 1)
                close (tokens->out);
            tokens->out = open(iter->cmd, O_RDWR|O_CREAT, 0644);
            printf("fd after open %d\n", tokens->out);
        }
        // else if (iter->type == 5 && !ft_strchr(iter->cmd, ">>"))
        // {
        //     if (tokens->out != 1)
        //         close(tokens->out);
        //     tokens->out = open(iter->cmd, O_RDWR|O_CREAT|O_APPEND, 0644);
        // }
        // else if (iter->type == 4 && !ft_strchr(iter->cmd, "<"))
        // {
        //     if (tokens->in != 1)
        //         close(tokens->in);
        //     tokens->in = open(iter->cmd, O_RDWR, 0644);
        //     if (tokens->in == -1)
        //         printf("infile:%s not found\n", iter->cmd);
        // }
        // else if (iter->type == 6 && !ft_strchr(iter->cmd, "<<"))
        //     her_dog(iter->cmd);
        if (iter->type == 7 || iter->next == NULL)
        {
            (tokens)->args = arg_strct;
            arg_strct = NULL;
            if (iter->type == 7)
            {
                (tokens)->next = tokens_new();
                tokens = tokens->next;
            }
        }
        iter = iter->next;
    }
    return (head);
}

void    expander(t_a9aw9o3 *tokens)//need a get_env function to get the env value and the linked list of env values
{
    char    *result;
    char    *buff;
    int     i;
    int     j;

    result = NULL;
    while (tokens)
    {
        i = 0;
        while (tokens->cmd[i])
        {
            j = 0;//the if below checks if $ is in herdog or '' and if $ have chars after it
            if (tokens->cmd[i] == '$' && get_qoutes(tokens->cmd, i) != 1 && is_alpha(tokens->cmd[i + 1]) && tokens->type != 6)
            {
                while (tokens->cmd[i + j] && is_alpha(tokens->cmd[i + j]))
                    ++j;
                buff = (char *)malloc(sizeof(char) * j + 1);
                j = 0;
                while (is_alpha(tokens->cmd[i + j]))
                {
                    buff[j] = tokens->cmd[i + j];
                    ++j;
                }
                buff[j] = '\0';
                result = getenv(buff);
                // printf("env %s\n", result);
                if (!result && (tokens->type >= 3 && tokens->type <= 5) && !get_qoutes(tokens->cmd, i))// the cases of ambigius redirection
                {
                    printf("%s ambigious redirectin\n", tokens->cmd + i);
                    tokens->err = 1;
                }
                // result = ft_strjoin_exp(tokens->cmd,  result, &i);
                // result = ft_strjoin_exp(result, tokens->cmd + i, &i);
                result = ft_strjoin_exp(tokens->cmd, result, i);
                result = ft_strjoin(result, tokens->cmd + i + j);
                tokens->cmd = result;
                free (result);
                printf("wow %s\n", tokens->cmd);
            }
            else
                ++i;
        }
        tokens = tokens->next;
    }
}
