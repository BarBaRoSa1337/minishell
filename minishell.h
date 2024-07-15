/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:33:43 by achakour          #+#    #+#             */
/*   Updated: 2024/07/13 11:59:24 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define  MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "/usr/include/readline/readline.h"
#include "/usr/include/readline/history.h"

#define CMD 1
#define FILE 2
#define FLAG 4
#define ARROW 5
#define DOG 6

typedef struct s_9aw9a3
{
    int cmd_found;
    char    *tmp;
    int index;
    int s;
    int d;
} t_9aw9aw3;

typedef struct s_a9aw9o3
{
    struct s_a9aw9o3    *next;
    char                *cmd;
} t_a9aw9o3;

char	    *ft_substr(char const *s, unsigned int start, size_t len);
size_t	    ft_strlcpy(char *dst, char *src, size_t dstsize);
void	    ft_lstadd_back(t_a9aw9o3 **lst, t_a9aw9o3 *new);
char	    *ft_strtrim(char const *s1, char const *set);
char	    *ft_strjoin(char const *s1, char const *s2);
char	    **ft_split(char const *s, char c);
int         get_qoutes(char *str, int index);
int	        ft_charchr(char c, char *find);
int         ft_strchr(char *s, char *find);
size_t	    ft_strlen(const char *str);
int         check_syntax(char *str);
int         check_quotes(char *str);
t_a9aw9o3	*ft_lstnew(char *arg);

#endif