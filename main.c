/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:36:58 by achakour          #+#    #+#             */
/*   Updated: 2024/07/28 10:10:41 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void    get_meta_chars(char *str, int *index, t_a9aw9o3 **shell)
{
    char    *buff;
    int     i;

    i = 0;
    while (ft_charchr(str[i], "<|>"))
        ++i;
    *index += i;
    buff = (char *)malloc(sizeof(char) * (i + 1));
    if (!buff)
        return ;
    ft_strlcpy(buff, str, (i + 1));
    ft_lstadd_back(shell, ft_lstnew(buff, 0));
}

void    get_none_quoted(char *str, int *index, t_a9aw9o3 **shell)
{
    char    *buff;
    int     i;

    i = 0;
    while (str[i])
    {
        if (ft_charchr(str[i], " <|> ") && get_qoutes(str, i) == 0)
            break;
        ++i;
    }
    *index += i;
    buff = (char *)malloc(sizeof(char) * (i + 1));
    if (!buff)
        return ;
    ft_strlcpy(buff, str, (i + 1));
    ft_lstadd_back(shell, ft_lstnew(buff, 0));
}

void    get_single_qoted(char *str, int *index, t_a9aw9o3 **shell)
{
    char    *buff;
    int     i;

    i = 0;
    while (str[i] != 39)
        ++i;
    while (str[i])
    {
        if (ft_charchr(str[i], " <|> ") && !get_qoutes(str, i))
            break;
        ++i;
    }
    *index += i;
    buff = (char *)malloc(sizeof(char) * (i + 1));
    if (!buff)
        return ;
    ft_strlcpy(buff, str, (i + 1));
    ft_lstadd_back(shell, ft_lstnew(buff, 1));
}

void    get_double_quoted(char *str, int *index, t_a9aw9o3 **shell)
{
    char    *buff;
    int     i;

    i = 0;
    while (str[i] != 34)
        ++i;
    while (str[i])
    {
        if (ft_charchr(str[i], " <|> ") && !get_qoutes(str, i))
            break;
        ++i;
    }
    *index += i;
    buff = (char *)malloc(sizeof(char) * (i + 1));
    if (!buff)
        return ;
    ft_strlcpy(buff, str, (i + 1));
    ft_lstadd_back(shell, ft_lstnew(buff, 2));
}

void zre3_btata_dk_lflah(char *str)
{
    t_a9aw9o3   *tokens;
    char        *buff;
    int         i;

    i = 0;
    tokens = NULL;
    while (str[i])
    {
        if (str[i] == '\"')
        {
            get_double_quoted(str + i, &i, &tokens);
        }
        else if (str[i] == '\'')
        {
            get_single_qoted(str + i, &i, &tokens);
        }
        else if (!get_qoutes(str, i) && !ft_charchr(str[i], " <|>\"\'"))
        {
            get_none_quoted(str + i, &i, &tokens);
        }
        else if (ft_charchr(str[i], "<|>") && !get_qoutes(str, i))
        {
            get_meta_chars(str + i, &i, &tokens);
        }
        else if (str[i] == ' ')
            ++i;
    }
    process_red(tokens);
    sanitize_tokens(tokens);
    expander(tokens);
    // remove_quotes(tokens);
    t_shell *lst = fill_struct(&tokens);
    printf("cmd %s\n", lst->cmd);
    printf("out %d\n", lst->out);
    printf("in %d\n", lst->in);
    t_arg *gg = lst->args;
    while (gg)
    {
        printf("args %s \n", gg->arg);
        gg = gg->next;
    }
    free (str);
    zre3_btata_dk_lflah(readline("minishell$:"));
}

#include <string.h>

int main(int ac, char **ar)
{
    char *input = readline("minishell $:");
    zre3_btata_dk_lflah(input);
    // int fd = open("out", O_RDWR|O_CREAT);
    // printf("%d\n", fd);
    // // close(fd);
    // fd = open("out", O_RDWR);
    // printf("%d\n", fd);
    // write(5,"hello",6);
    // read_history(input);
    return (0);
}
