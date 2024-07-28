/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achakour <achakour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:33:43 by achakour          #+#    #+#             */
/*   Updated: 2024/07/27 18:55:03 by achakour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
#define  PARSING_H

#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h> 
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 13
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

#define CMD 1
#define FLAG 2
#define O_FILE 3
#define IN_FILE 4
#define APP_OUT 5
#define DOG 6
#define PIPE 7

typedef struct s_a9aw9o3
{
    struct s_a9aw9o3    *next;
    char                *cmd;
    int     quoted;
    int     type;
    int     err;
} t_a9aw9o3;

typedef struct s_arg
{
    char *arg;
    struct s_arg *next;
} t_arg;

typedef struct s_shell
{
    int in;
    int out;
    char *cmd;
    t_arg *args;
    int     err;
    struct s_shell *next;
} t_shell;

char	*get_next_line(int fd);
char	*ft_strjoin_exp(char *s1, char *s2, int index);
char	*ft_strjoin(char *s1, char *s2);
size_t	    ft_strlcpy(char *dst, char *src, size_t dstsize);
void	    ft_lstadd_back(t_a9aw9o3 **lst, t_a9aw9o3 *new);
t_a9aw9o3	*ft_lstnew(char *arg, int quote_type);
void        remove_quotes(t_a9aw9o3 *tokens);
int         get_qoutes(char *str, int index);
void        sanitize_tokens(t_a9aw9o3 *cmd);
int	        ft_charchr(char c, char *find);
int         ft_strchr(char *s, char *find);
void        zre3_btata_dk_lflah(char *str);
t_shell     *fill_struct(t_a9aw9o3 **cmd);
void        expander(t_a9aw9o3 *tokens);
int is_alpha(char c);
void        process_red(t_a9aw9o3 *cmd);
char	    *ft_strdup(const char *str);
size_t	    ft_strlen(const char *str);
int         check_syntax(char *str);
int         check_quotes(char *str);

#endif