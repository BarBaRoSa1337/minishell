#ifndef MINISHELL_H
# define MINISHELL_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define PATH_SIZE 500

# include <fcntl.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>
# include <sys/wait.h>


typedef struct s_var  // for pipex functions
{
	char	**cmd_1;
	char	**cmd_2;
	char	*cmd_path_1;
	char	*cmd_path_2;
}			t_var;

typedef struct s_env // for store the env
{
    char *key;
    char *value;
    struct s_env *next;
} t_env;

typedef struct s_arg
{
    char *arg;
    struct s_arg *next;
} t_arg;

typedef struct s_shell // comming from parsing  
{                                    
    int in;
    int out;                      
    char *cmd;
    t_arg *argument;
    struct s_shell *next;                          
} t_shell; 

typedef struct s_ms // struct for execution
{
    int  pid;
    char *cmd;
    int infile;
    char **arg;
    int outfile;
    struct s_ms *next;
} t_ms;

/*********************    Linked_list    *******************/

t_ms			*ft_lstnew(void);
t_ms			*ft_lstlast(t_ms *lst);
void				ft_lstadd_back(t_ms **lst, t_ms *new);
void				ft_lstadd_front(t_ms **lst, t_ms *new);

/**********************     LIBFT    **********************/

char	*ft_itoa(int n);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_isdigit( int c );
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
void	ft_putnbr_fd(int n, int fd);
void	ft_bzero(void *s, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	*ft_memmove( void *dst, const void *src, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

/******************* printf  ********************/

int			ft_putnbr(int c, int len);
int			ft_putchar(char c, int len);
int			ft_putstr(char *s, int len);
int			ft_printf(const char *str, ...);
int			ft_check(char s, va_list args, int len);
int			ft_put_positive(unsigned int c, int len);
int			ft_put_adress(unsigned long decimal, int len);
int			ft_decimal_to_hex(unsigned long decimal, int len);
int			ft_decimal_to_hexa(unsigned int decimal, int len);

/**************** pipex  *******************/

void	    check_cmd(t_ms **e, t_env *v);
char		*if_accessible(char *cmd, char *env);
void		ft_pipe(char **av, char **env, t_var *var);

/**************** get_next_line  *******************/

char		*get_next_line(int fd);
char		*returnline(char *buffer);
char		*ft_readfile(int fd, char *buffer);

/**************** builtins  *******************/

void build_pwd(void);
void build_env(t_env *v);
void build_exit(char **status);
void build_cd(char **direction);
void build_unset(char **str, t_env **v);
void build_export(char **str, t_env **v);
void build_echo(char **str, int fd);

/************** env_linked_list  ****************/

t_env *env_lstnew(void);
t_env *split_env(char *str);
t_env *env_lstlast(t_env *lst);
void get_envp(char **envp, t_env **head);
void env_lstadd_back(t_env **lst, t_env *new);
void env_lstadd_front(t_env **lst, t_env *new);

/******************* execution ********************/

void	ft_free(char **ptr);
char    *searsh_env(t_env *v);
int     multiple_arg(char **ptr);
int     simple_execute(t_ms *e, char **env);
int     execute_builtins(t_ms *e, t_env **v);
void    forming_list(t_ms **my_struct, t_shell *shell);
void    execute_cmd(t_ms **e, t_env *v, char **envp, int tmp);

void    node_1(t_shell **e);
void    node_2(t_shell **e);
void    node_3(t_shell **e);
t_shell	*new_node(void);

# endif