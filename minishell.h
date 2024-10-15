/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:33:43 by achakour          #+#    #+#             */
/*   Updated: 2024/09/12 23:35:43 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <fcntl.h>
# include <dirent.h>
# include <limits.h>
# include <signal.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include <readline/history.h>
# include <readline/readline.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define PATH_SIZE 100000

# define CMD 1
# define FLAG 2
# define O_FILE 3
# define IN_FILE 4
# define APP_OUT 5
# define DOG 6
# define PIPE 7

extern int		g_exit_status;

typedef struct s_heredoc
{
	int					fd;
	struct s_heredoc	*next;
}						t_heredoc;

typedef struct s_a9aw9o3 // storing data while parsing
{
	int					err;
	char				*cmd;
	int					type;
	struct s_a9aw9o3	*next;
	int					quoted;
}						t_a9aw9o3;

typedef struct s_arg // storing args as linkd list
{
	char			*arg;
	struct s_arg	*next;
}						t_arg;

typedef struct s_shell // send to execution
{
	int				in;
	int				out;
	int				err;
	char			*cmd;
	t_arg			*args;
	struct s_shell	*next;
}						t_shell;

typedef struct s_var // for pipex functions
{
	char	**cmd_1;
	char	**cmd_2;
	char	*cmd_path_1;
	char	*cmd_path_2;
}						t_var;

typedef struct s_env // for storing the env
{
	int				i;
	int				j;
	char			*key;
	char			*value;
	struct s_env	*next;
}						t_env;

typedef struct s_ms // build to execute cmd
{
	int			pid;
	char		*cmd;
	char		**arg;
	int			error;
	int			infile;
	int			outfile;
	struct s_ms	*next;
}						t_ms;

typedef struct s_pars
{
	int					i;
	int					j;
	int					flag;
	char				**buffer;
	char				*buff;
	char				*tmp;
	t_a9aw9o3			*head;
	t_a9aw9o3			*iter;
	t_shell				*heads;
	int					before;
	t_shell				*tokens;
	t_heredoc			*heredoc;
	t_heredoc			*her_head;
	int					cmd_found;
	t_arg				*arg_strct;
}						t_pars;

/********************* Parsing **********************/

t_shell					*tokens_new(void);
int						is_join(char *str);
int						is_exp(char *buff);
int						is_alphanum(char c);
t_arg					*arg_new(char *cmd);
int						space_exp(char *exp);
void					free_exp(char **buff);
char					**exp_split(char *str);
char					*get_4_join(char *str);
t_a9aw9o3				*lstnew_exp(char *arg);
int						check_quotes(char *str);
int						check_syntax(char *buff);
void					process_red(t_a9aw9o3 *cmd);
int						ft_charchr(char c, char *find);
t_shell					*parsing(char *str, t_env *env);
char					*ft_get_str(char *str, int len);
int						ft_strchar(char *s, char *find);
void					sanitize_tokens(t_a9aw9o3 *cmd);
char					*get_env(char *buff, t_env *env);
int						get_qoutes(char *str, int index);
int						get_qoutes(char *str, int index);
void					remove_quotes(t_a9aw9o3 *tokens);
char					*ft_strjoin_ex(char *s1, char *s2);
char					*ft_strjoin_exp(char *s1, char *s2);
void					lst_rje3_lor(t_arg **lst, t_arg *new);
void					expander(t_a9aw9o3 *tokens, t_env *env);
void					ft_cmd_clear(t_a9aw9o3 **cmd, t_pars *p);
t_shell					*fill_struct(t_a9aw9o3 **cmd, t_env *env);
t_heredoc				*heredoc_iter(t_a9aw9o3 *head, t_env *env);
t_a9aw9o3				*lstnew_9aw9a3a(char *arg, int quote_type);
void					open_infile(t_a9aw9o3 *iter, t_shell *tokens);
int						ft_heredoc(char *del, t_env *env, int quotes);
void					add_back_9aw9a3a(t_a9aw9o3 **lst, t_a9aw9o3 *new);
char					*expander_cont(char *str, int x, int *y, t_env *env);
void					exp_copy(t_a9aw9o3 *tokens, char *result, int i, int j);
void					handle_space_exp(t_a9aw9o3 *lst, t_a9aw9o3 *next_node,
							char *str);

/*********************    Linked_list    *******************/

t_ms					*ft_lstnew(void);
t_ms					*ft_lstlast(t_ms *lst);
void					ft_lstadd_back(t_ms **lst, t_ms *new);
void					ft_lstadd_front(t_ms **lst, t_ms *new);

/**********************     LIBFT    ***********************/

char					*ft_itoa(int n);
int						is_alpha(char c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);
int						ft_isdigit(int c);
size_t					ft_strlen(char *s);
char					*ft_strdup(char *s1);
int						ft_atoi(char *str);
void					ft_putnbr_fd(int n, int fd);
char					*ft_strrchr(char *s, int c);
void					ft_bzero(void *s, size_t n);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char *s, int fd);
void					ft_putendl_fd(char *s, int fd);
char					*ft_strjoin(char *s1, char *s2);
char					*ft_strchr(char *s, int c);
char					**ft_split(char *s, char c);
void					*ft_calloc(size_t count, size_t size);
void					*ft_memset(void *b, int c, size_t len);
void					*ft_memchr(void *s, int c, size_t n);
char					*ft_strtrim(char *s1, char *set);
size_t					ft_strlcat(char *dst, char *src, size_t dstsize);
size_t					ft_strlcpy(char *dst, char *src, size_t dstsize);
void					*ft_memcpy(void *dest, void *src, size_t n);
int						ft_memcmp(void *s1, void *s2, size_t n);
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
void					*ft_memmove(void *dst, void *src, size_t len);
int						ft_strncmp(char *s1, char *s2, size_t n);
char					*ft_substr(char *s, unsigned int start, size_t len);
char					*ft_strmapi(char *s, char (*f)(unsigned int, char));
char					*ft_strnstr(char *haystack, char *needle, size_t len);

/************************ printf  *************************/

int						ft_putnbr(int c, int len);
int						ft_putchar(char c, int len);
int						ft_putstr(char *s, int len);
int						ft_printf(const char *str, ...);
int						ft_check(char s, va_list args, int len);
int						ft_put_positive(unsigned int c, int len);
int						ft_put_adress(unsigned long decimal, int len);
int						ft_decimal_to_hex(unsigned long decimal, int len);
int						ft_decimal_to_hexa(unsigned int decimal, int len);

/******************* builtins  **********************/

void					swap(t_env *v);
void					sig(int signal);
void					handler(int signal);
void					get_order(t_env *v);
void					sig_quit(int signal);
t_env					*make_copy(t_env *v);
void					print_copy(t_env *v);
int						is_builtins(t_ms *e);
void					build_pwd(char **ptr);
void					build_exit(char **status);
void					build_echo(char **str, int fd);
void					build_env(t_env *v, char **ptr);
void					build_export(char **str, t_env **v);
void					update_value(t_env **v, t_env *new);
t_env					*export_split(char *str, t_env **v);
void					build_cd(char **direction, t_env **v);
void					build_unset(char **str, t_env **v, int i);

/*************** env_linked_list  ******************/

t_env					*env_lstnew(void);
t_env					*env_lstlast(t_env *lst);
t_env					*split_env(char *str, int i, int j);
void					get_envp(char **envp, t_env **head);
void					env_lstadd_back(t_env **lst, t_env *new);
void					env_lstadd_front(t_env **lst, t_env *new);

/******************* execution ********************/

void					free_ms(t_ms **ms);
int						valid_alpha(char c);
void					free_env(t_env **v);
void					ft_free(char **ptr);
int						str_valid(char *str);
char					**env_to_ptr(t_env *v);
int						multiple_arg(char **ptr);
void					free_shell(t_shell **shell);
int						ft_strcmp(char *s1, char *s2);
void					check_cmd(t_ms **e, t_env *v);
char					*env_searsh(t_env *v, char *find);
t_ms					*forming_list(t_shell *shell, int i);
char					*if_accessible(char *cmd, char *env);
int						execute_builtins(t_ms *e, t_env **v);
void					ft_pipe(char **av, char **env, t_var *var);
void					update_env(t_env **env, char *key, char *new_value);
void					execute_cmd(t_ms **e, t_env **v, char **envp, int tmp);
int						simple_execute(t_ms *e, char **env, t_env **v,
							int pipe_in);

#endif