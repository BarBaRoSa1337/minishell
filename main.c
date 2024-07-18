/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:36:58 by achakour          #+#    #+#             */
/*   Updated: 2024/07/18 10:46:42 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
    printf("M %s\n", buff);
    ft_lstadd_back(shell, ft_lstnew(buff, 0));
}

void    get_none_quoted(char *str, int *index, t_a9aw9o3 **shell)
{
    char    *buff;
    int     i;

    i = 0;
    while (str[i])
    {
        if (ft_charchr(str[i], " <|> "))
            break;
        ++i;
    }
    *index += i;
    buff = (char *)malloc(sizeof(char) * (i + 1));
    if (!buff)
        return ;
    ft_strlcpy(buff, str, (i + 1));
    printf("N %s\n", buff);
    ft_lstadd_back(shell, ft_lstnew(buff, 0));
}

void    get_single_qoted(char *str, int *index, t_a9aw9o3 **shell)
{
    char    *buff;
    int i;

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
        printf("S %c\n", buff[i]);
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
    printf("D %c\n", buff[i]);
    ft_lstadd_back(shell, ft_lstnew(buff, 2));
}

t_a9aw9o3   *process_cmd(char *str)
{
    t_a9aw9o3   *tokens;
    char        *buff;
    int         i;

    i = 0;
    tokens = NULL;
    while (str[i])
    {
        // if (str[i] == '\"')
        // {
        //     get_double_quoted(str, &i, &tokens);
        // }
        // else if (str[i] == '\'')
        // {
        //     get_single_qoted(str, &i, &tokens);
        // }
        if (!get_qoutes(str, i) && !ft_charchr(str[i], " <|>\"\'"))
        {
            get_none_quoted(str + i, &i, &tokens);
        }
        else if (ft_charchr(str[i], "<|>;") && !get_qoutes(str, i))
        {
            sleep(1);
            get_meta_chars(str + i, &i, &tokens);
        }
        else if (str[i] == ' ')
            ++i;
    }
    return (tokens);
}

#include <string.h>

int main(int ac, char **ar)
{
    char *input = readline("minishell $:");
    process_cmd(input);
    // read_history(input);
    // printf("%s\n", getenv("USER"));
    return (0);
}
